

#include <stdint.h>
#include "ucos_ii.h"
#include "sys_services.h"
#include "timer.h"


#define SYNC_DPLL_DIV_COUNT_LIM_HDMI  0x0001ADB0           /* maximum usefull value (=110000 => ~0.1 ppm)
                                                              it results in 0x00093B48 for the audio clock div_count */
#define SYNC_DPLL_MIN_DIV_COUNT       0x72                 /* = 114: minimum fractional divider => means ~100 ppm correction */
#define SYNC_DPLL_DIV_COUNT_CORR_HD   545                  /* correction value to match HD clock to SD clock in NTSC modes */
#define SYNC_DPLL_SENSITIVITY         256                  /* with smaller SENSITIVITY, regulation reacts faster but
                                                              making it too fast may cause instability */

#define SYNC_DPLL_HDMI_CONVERSION(x)  ((x/2)*11)           /* ratio conversion is 12*11/24 */



//23492740
uint8_t bData_23492740 = 0; //23492740 +0
uint32_t divCount = 0; //23492744 +4
int Data_23492748 = -1; //23492748 +8
int Data_2349274c = 0; //2349274c +0xc
uint32_t Data_23492750 = 5; //23492750 +0x10
uint32_t syncState = 0; //23492754 +0x14
int syncStcRegulation = 0; //23492758 +0x18
int syncUseFd2as54Mhz = 0; //2349275c +0x1c
uint32_t averageFill = 0; //23492760 +0x20
uint32_t averageIndex = 0; //23492764 +0x24
uint32_t currentPcr = 0; //23492768 +0x28
uint32_t currentStc = 0; //2349276c +0x2c
uint32_t previousPcr = 0; //23492770 +0x30
uint32_t previousStc = 0; //23492774 +0x34
uint64_t previousTimeStamp = 0; //23492778 +0x38


int64_t avStcPcrDiff[10]; //235f36d8
int64_t avStcPcrDeltaDiff[10]; //235f3728


void clkpwr_SetDpllconfig_PptCountReg(uint32_t);
void clkpwr_SetDpllconfig_EnDpllhdmi(int);
void clkpwr_SetDpllconfig_EnDpllfd1(int);
void clkpwr_SetDpllconfig_EnDpllfd2(int);
void clkpwr_SetDpllconfig_EnDpllfd3(int);
void clkpwr_SetDpllconfig_EnPptHdmi(int);
void clkpwr_SetDpllconfig_IncPptHdmi(int);
void clkpwr_SetDpllconfig_IncFreqhdmi(int);
void clkpwr_SetDpllconfig_IncFreqfd1(int);
void clkpwr_SetDpllconfig_IncFreqfd2(int);
void clkpwr_SetDpllconfig_IncFreqfd3(int);
void syncReloadPcr(int a);
void clkpwr_SetFd2audio_ResetFd2(int);
uint64_t syncGetStc(int);

/* 234353d8 - todo */
void syncReset()
{
	memset(&avStcPcrDiff[0], 0, sizeof(avStcPcrDiff));
	memset(&avStcPcrDeltaDiff[0], 0, sizeof(avStcPcrDeltaDiff));

	averageFill = 0;
	averageIndex = 0;
	currentPcr = 0;
	currentStc = 0;
	previousPcr = -1;
	previousStc = -1;
	bData_23492740 = 0;
	divCount = 110000;
	syncState = 0;
	Data_23492750 = 5;
	syncState = 0;

	clkpwr_SetDpllconfig_EnDpllhdmi(0);
	clkpwr_SetDpllconfig_EnDpllfd1(0);
	clkpwr_SetDpllconfig_EnDpllfd2(0);
	clkpwr_SetDpllconfig_EnDpllfd3(0);

	FREG(0xca000060)[0] = 0x1adaf;
	FREG(0xca000064)[0] = 0x93b47;
	FREG(0xca000068)[0] = 0x93b47;
	FREG(0xca00006c)[0] = 0x93b47;

	clkpwr_SetDpllconfig_IncFreqhdmi(0);
	clkpwr_SetDpllconfig_IncFreqfd1(0);
	clkpwr_SetDpllconfig_IncFreqfd2(0);
	clkpwr_SetDpllconfig_IncFreqfd3(0);

	if (syncUseFd2as54Mhz != 0)
	{
		//0x23435490
		clkpwr_SetDpllconfig_PptCountReg(0x2d);
		clkpwr_SetDpllconfig_EnPptHdmi(1);
		clkpwr_SetDpllconfig_IncPptHdmi(0);
		clkpwr_SetDpllconfig_IncFreqhdmi(0);

		FREG(0xca000060)[0] = 0x221;

		clkpwr_SetDpllconfig_EnDpllhdmi(1);
	}
	else
	{
		//loc_234354c4
		clkpwr_SetDpllconfig_PptCountReg(0);
		clkpwr_SetDpllconfig_EnPptHdmi(0);
		clkpwr_SetDpllconfig_IncPptHdmi(0);
	}
}


/* 234354e0 - todo */
void syncSetDivCountValues()
{
#if 0
	console_send_string("syncSetDivCountValues (todo.c): TODO\r\n");
#endif

    uint32_t pptCount, fdDivCount, hdDivCount;
    uint64_t hdDivCount_num, hdDivCount_denom; /* nominator and denomiator
                                                  for hdDivCount calculation */

    divCount  &= 0xFFFFFFFE; /* make value an integer multiple of 2 */
    /* check useful limit */
    if (divCount > SYNC_DPLL_DIV_COUNT_LIM_HDMI)
    {
        divCount = (uint32_t)SYNC_DPLL_DIV_COUNT_LIM_HDMI;
    }
    else if (divCount < SYNC_DPLL_MIN_DIV_COUNT)
    {
        divCount = (uint32_t)SYNC_DPLL_MIN_DIV_COUNT;
    }

    /* set divider to new value */
    if (syncUseFd2as54Mhz)
    {   /* HD is set to 720 or 1080 and frame rate is set to 29.97 fps */
        if (bData_23492740/*increase*/ == 1) //SYNC_DPLL_INCREASE_SPEED)
        {
        	//0x23435530
            /* default values to correct the HD clock */
            pptCount = 45;
            /* SYNC_DPLL_DECREASE_SPEED has to be set for HD DPLL only */
            clkpwr_SetDpllconfig_IncFreqhdmi(0/*SYNC_DPLL_DECREASE_SPEED*/);
            /* Divcount has to be set to a special value for HD DPLL only */
            hdDivCount = SYNC_DPLL_DIV_COUNT_CORR_HD;
            /* fdDivCount does not directly matter because the fd DPLLs are
               disabled. Just in case the enabling happens again before
               the right value is set, i want to keep the register up-to-date */
            fdDivCount = SYNC_DPLL_HDMI_CONVERSION(divCount)-1;
            /* enable only HDMI DPLL */
            clkpwr_SetDpllconfig_EnDpllhdmi(1);
            clkpwr_SetDpllconfig_EnDpllfd1(0);
            clkpwr_SetDpllconfig_EnDpllfd2(0);
            clkpwr_SetDpllconfig_EnDpllfd3(0);
            //0x23435688
        }
        else
        {
        	//loc_23435570
            fdDivCount = SYNC_DPLL_HDMI_CONVERSION(divCount);
            if (fdDivCount <= 749)
                pptCount = 40;
            else if (fdDivCount <= 1074)
                pptCount = 41;
            else if (fdDivCount <= 1833)
                pptCount = 42;
            else if (fdDivCount <= 5624)
                pptCount = 43;
            else
                pptCount = 44;

            hdDivCount_num   = 1001 * (((uint64_t)pptCount+1) * ((16 * (uint64_t)fdDivCount)+1));
            hdDivCount_denom  = 4004 * ((16 * (uint64_t)fdDivCount)+1);
            hdDivCount_denom -= 88 * ((uint64_t)pptCount+1) * ((16 * (uint64_t)fdDivCount)+1001);
            hdDivCount_num  += hdDivCount_denom >> 1;           // for rounding
            hdDivCount = (uint32_t)(hdDivCount_num / hdDivCount_denom);

            hdDivCount -= 1; // correct value for register must be -1
            fdDivCount -= 1; // correct value for register must be -1
            /* set change direction */
            clkpwr_SetDpllconfig_IncFreqhdmi(1/*SYNC_DPLL_INCREASE_SPEED*/);
            /* enable all DPLLs */
            clkpwr_SetDpllconfig_EnDpllhdmi(1);
            clkpwr_SetDpllconfig_EnDpllfd1(1);
            clkpwr_SetDpllconfig_EnDpllfd2(1);
            clkpwr_SetDpllconfig_EnDpllfd3(1);
        }
        /* set PPT counter */
        clkpwr_SetDpllconfig_PptCountReg(pptCount);
        clkpwr_SetDpllconfig_EnPptHdmi(1);
        clkpwr_SetDpllconfig_IncPptHdmi(0);
    }
    else
    {   /* PAL case and case when HD output is set to 480/576 */
    	//loc_234356d4
        hdDivCount = divCount-1;
        fdDivCount = SYNC_DPLL_HDMI_CONVERSION(divCount)-1;
        /* set change direction */
        clkpwr_SetDpllconfig_IncFreqhdmi(bData_23492740/*increase*/);
        /* enable DPLL */
        clkpwr_SetDpllconfig_EnDpllhdmi(1);
        clkpwr_SetDpllconfig_EnDpllfd1(1);
        clkpwr_SetDpllconfig_EnDpllfd2(1);
        clkpwr_SetDpllconfig_EnDpllfd3(1);
        /* reset PPT counter */
        clkpwr_SetDpllconfig_PptCountReg(0);
        clkpwr_SetDpllconfig_EnPptHdmi(0);
        clkpwr_SetDpllconfig_IncPptHdmi(0);
    }
    /* set divcount values for all fd clocks */
    FREG(0xca000060)[0] = hdDivCount; // FREG_CLKPWR_SetDplldivcounthdmi(hdDivCount);
    FREG(0xca000064)[0] = fdDivCount; // FREG_CLKPWR_SetDplldivcountfd1(fdDivCount);
    FREG(0xca000068)[0] = fdDivCount; // FREG_CLKPWR_SetDplldivcountfd2(fdDivCount);
    FREG(0xca00006c)[0] = fdDivCount; // FREG_CLKPWR_SetDplldivcountfd3(fdDivCount);
    /* change-direction is identical for all fd clocks */
    clkpwr_SetDpllconfig_IncFreqfd1(bData_23492740/*increase*/);
    clkpwr_SetDpllconfig_IncFreqfd2(bData_23492740/*increase*/);
    clkpwr_SetDpllconfig_IncFreqfd3(bData_23492740/*increase*/);
}


/* 2343571c - complete */
void syncDpllSlower(uint32_t regFactor)
{
#if 0
	console_send_string("syncDpllSlower (todo.c): TODO\r\n");
#endif

    if (bData_23492740 == 1) //SYNC_DPLL_INCREASE_SPEED)
    {   /* Regulation is set to make it faster */
        /* Can we make it less fast ? */
        if (divCount < SYNC_DPLL_DIV_COUNT_LIM_HDMI)
        {
            if (divCount > (SYNC_DPLL_SENSITIVITY*regFactor))
            {
                divCount += (divCount / SYNC_DPLL_SENSITIVITY) * regFactor;
            }
            else
            {
                divCount += regFactor; /* make sure it will increase */
            }
        }
        else
        {   /* we have to change the polarity */
            /* decrease */
        	bData_23492740 = 0; //SYNC_DPLL_DECREASE_SPEED;
        }

        syncSetDivCountValues();
    }
    else if (bData_23492740 == 0) //SYNC_DPLL_DECREASE_SPEED)
    {   /* Regulation is already set to make it slower */
        /* We have to further decrease the divCount value */
        if (divCount > SYNC_DPLL_MIN_DIV_COUNT) /* limit setting */
        {
            if (divCount > (SYNC_DPLL_SENSITIVITY*regFactor))
            {
                divCount -= (divCount / SYNC_DPLL_SENSITIVITY) * regFactor;
            }
            else
            {
                divCount = (uint32_t)(divCount-regFactor); /* make sure it will decrease */
            }

            syncSetDivCountValues();
        }
        /* else : limit of regulation was reached - no further adjustment */
    }
    /* else: STC is slower and we leave it like this */
}


/* 23435780 - complete */
void syncDpllFaster(uint32_t regFactor)
{
#if 0
	console_send_string("syncDpllFaster (todo.c): TODO\r\n");
#endif

    int32_t  change             = 0;

    if ( bData_23492740 == 1) //SYNC_DPLL_INCREASE_SPEED )
    {   /* Regulation is set to make it faster */
        /* We have to further decrease the divCount value */
        if (divCount > SYNC_DPLL_MIN_DIV_COUNT) /* limit setting */
        {
            if (divCount > (SYNC_DPLL_SENSITIVITY*regFactor))
            {
                divCount -= (divCount / SYNC_DPLL_SENSITIVITY) * regFactor;
            }
            else
            {
                divCount -= regFactor; /* make sure it will decrease */
            }
            change = 1;
        }
        /* else : limit of regulation was reached - no further adjustment */
    }
    else if ( bData_23492740 == 0) //SYNC_DPLL_DECREASE_SPEED )
    {   /* Regulation is set to make it slower */
        /* Can we make it less slow ? */
        if (divCount < SYNC_DPLL_DIV_COUNT_LIM_HDMI)
        {
            if (divCount > (SYNC_DPLL_SENSITIVITY*regFactor))
            {
                divCount += (divCount / SYNC_DPLL_SENSITIVITY) * regFactor;
            }
            else
            {
                divCount += regFactor; /* make sure it will increase */
            }
        }
        else
        {   /* we have to change the polarity */
            /* increase */
            bData_23492740 = 1; //SYNC_DPLL_INCREASE_SPEED;
        }
        change = 1;
    }
    if (change != 0)
    {
        syncSetDivCountValues();
    } /* if (change != 0) */
}


/* 234357e4 / 23443838 - todo */
void sync_PcrNotifier()
{
#if 0
	console_send_string("sync_PcrNotifier (todo.c): TODO\r\n");
#endif

    int64_t  stcPcrDiff;
    int64_t  stcPcrDeltaDiff, stcPcrDeltaDiff2, stcPcrDeltaVariance;
    int64_t  deltaStc/*sp8*/, deltaPcr/*sp*/;
    uint64_t pcr;
    uint32_t stc, base, extension;
    uint32_t regFactor;

	uint64_t timeStamp = timer_get_timestamp(1);

	if (syncStcRegulation != 0)
	{
		//0x2343580c
		pcr = FREG(0xc800012c)[0]; //TSD01_PCR_LOWER
		base = (pcr >> 9);
		base *= 300; //TSD_EXTENSION_RESOLUTION
		base &= 0x007FFFFF;

		extension = pcr & 0x1FF;
		pcr/*r7*/ = base + extension;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sync_PcrNotifier: pcr=%d\r\n", pcr);
			console_send_string(debug_string);
		}
#endif

		currentPcr = pcr; //r7;

		stc = FREG(0xc8000124)[0]; //TSD01_CURRENT_STC_LOWER
		base = (stc >> 9);
		base *= 300; //TSD_EXTENSION_RESOLUTION
		base &= 0x007FFFFF;

		extension = stc & 0x1FF;
		stc = base + extension;
		stc/*r6*/ += 1100;

#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "sync_PcrNotifier: stc=%d\r\n", stc);
			console_send_string(debug_string);
		}
#endif

		currentStc = stc; //r6;

		/* check for valid previous time information. If invalid, wait for next call */
		if ((previousStc == -1) || (previousPcr == -1))
		{
			previousPcr = currentPcr;
			previousStc = currentStc;
			//->loc_23435aa8
			previousTimeStamp = timeStamp;
			return;
		}
		//0x23435884
		if (stc/*r6*/ < previousStc/*r1*/)
		{
			stc += 0x96000000; //SYNC_MAX_STC_PACK_VALUE
		}

		if (pcr < previousPcr/*r0*/)
		{
			pcr += 0x96000000;
		}
		//loc_234358a0
		/* calculate deltas based on the swap-corrected values */
		deltaStc = (int64_t)stc - previousStc;
		deltaPcr = (int64_t)pcr - previousPcr;

		previousPcr = currentPcr;
		previousStc = currentStc;

		if (syncState == 0)
		{
			//0x234358e0
			Data_23492748 = -1;
			syncState = 1;

			clkpwr_SetDpllconfig_EnDpllhdmi(0);
			clkpwr_SetDpllconfig_EnDpllfd1(0);
			clkpwr_SetDpllconfig_EnDpllfd2(0);
			clkpwr_SetDpllconfig_EnDpllfd3(0);

			if (syncUseFd2as54Mhz != 0)
			{
				//0x2343591c
				clkpwr_SetDpllconfig_PptCountReg(0x2d);
				clkpwr_SetDpllconfig_EnPptHdmi(1);
				clkpwr_SetDpllconfig_IncPptHdmi(0);
				clkpwr_SetDpllconfig_IncFreqhdmi(0);

				FREG(0xca000060)[0] = 0x221; //DPLLDIVCOUNTHDMI

				clkpwr_SetDpllconfig_EnDpllhdmi(1);
				//->loc_2343596c
			}
			else
			{
				//loc_23435954
				clkpwr_SetDpllconfig_PptCountReg(0);
				clkpwr_SetDpllconfig_EnPptHdmi(0);
				clkpwr_SetDpllconfig_IncPptHdmi(0);
			}
			//loc_2343596c
			syncReloadPcr(0);
			//->loc_23435aa8
			previousTimeStamp = timeStamp;

			return;
		} //if (syncState == 0)
		//loc_23435978
		/*else*/ if (syncState == 1)
		{
			syncState = 2;
			//->loc_23435aa8
			previousTimeStamp = timeStamp;

			return;
		}
		//0x23435988
		if (( (int64_t)(timeStamp - previousTimeStamp) > (((deltaPcr / 27) * 11) / 10) ) ||
				((int64_t)(timeStamp - previousTimeStamp) < (((deltaPcr / 27) * 9) / 10) ))
		{
			//loc_23435aa8
			previousTimeStamp = timeStamp;

			return;
		}
		//0x23435a18
		else if (( (int64_t)(timeStamp - previousTimeStamp) > (((deltaStc / 27) * 11) / 10) ) ||
				((int64_t)(timeStamp - previousTimeStamp) < (((deltaStc / 27) * 9) / 10)) )
		{
			//loc_23435aa8
			previousTimeStamp = timeStamp;

			return;
		}
		else
		{
			//loc_23435ab4
			previousTimeStamp = timeStamp;
		}
		//uint64_t sp_0x2c = r6 - r7;
	    if( (llabs((int64_t)stc - (int64_t)pcr) > (int64_t)(6750000/*maxDelta*/))) /* about 11ms */
	    {
	    	syncReset();
	        return;
	    }
	    //0x23435ae4
	    /* calculate average diff values in case the STC is reliable */
	    stcPcrDiff          = 0;
	    stcPcrDeltaDiff     = 0;
	    stcPcrDeltaDiff2    = 0;
	    stcPcrDeltaVariance = 0;

	    if (syncState > 3) //(SYNC_DPLL_STATE_ADJUSTING_START+1))
	    {   /* the first STC value is not up-to-date */
	        /* get current STC / PCR and calculate delta */
	        avStcPcrDiff[averageIndex] = (int64_t)stc - (int64_t)pcr;
	        avStcPcrDeltaDiff[averageIndex] = deltaStc - deltaPcr;

	        /* calculate average stcPcrDeltaDiff value */
	        for (uint32_t ii = 0; ii <= averageFill; ii++)
	        {
	        	//loc_23435b64
	            stcPcrDiff/*r8_sb*/      += avStcPcrDiff[ii];
	            stcPcrDeltaDiff/*r4_r5*/ += avStcPcrDeltaDiff[ii];
	        }
	        //0x23435b98
	        stcPcrDeltaDiff2 = stcPcrDeltaDiff; /* save high resolution delta diff */
	        stcPcrDiff       = stcPcrDiff / ((int64_t)averageFill + 1);
	        stcPcrDeltaDiff  = stcPcrDeltaDiff / ((int64_t)averageFill + 1);

	        /* calculate variance to the stcPcrDeltaDiff average */
	        for (uint32_t ii = 0; ii <= averageFill; ii++)
	        {
	        	//loc_23435bf8
	            stcPcrDeltaVariance += (avStcPcrDeltaDiff[ii] - stcPcrDeltaDiff) *
	                                   (avStcPcrDeltaDiff[ii] - stcPcrDeltaDiff);
	        }
	        //0x23435c2c
	        stcPcrDeltaVariance = stcPcrDeltaVariance / ((int64_t)averageFill + 1);
	        /* increment average index counter and wrap around if necessary */
	        if (averageFill < 9) //(SYNC_DPLL_AVERAGE_ADJ_COUNT-1))
	        {
	        	averageFill++; /* value stops at SYNC_DPLL_AVERAGE_ADJ_COUNT-1 */
	        }
	        /* increment and wrap around index for average array */
	        averageIndex++;
	        if (averageIndex >= 10) //SYNC_DPLL_AVERAGE_ADJ_COUNT)
	        {
	        	averageIndex = 0;
	        }
	    }
	    //loc_23435c70
	    /******************/
	    /* STC regulation */
	    /* wait time      */
	    /******************/
	    if (syncState < 12) //SYNC_DPLL_STATE_FIRST_ADJUSTMENT)
	    {   /* waiting for some time to get reliable time information */

	    	syncState++;
	    	//->loc_23435d38
	        return;
	    }
	    else if (syncState == 12) //SYNC_DPLL_STATE_FIRST_ADJUSTMENT)
	    {
	    	//0x23435c90
	        if (stcPcrDeltaVariance < 100000L) //SYNC_MAX_PCR_VARIANCE)
	        {
	        	//0x23435c9c
	            if(stcPcrDeltaDiff != 0)
	            {
	            	//0x23435cb8
	            	int r6;
	                r6  = (uint32_t)((uint32_t)81/*SYNC_DPLL_STEP_FREQ_MHZ*/ * (uint32_t)llabs(deltaStc));
	                r6 /= (uint32_t)llabs(stcPcrDeltaDiff) * (uint32_t)22/*SYNC_594_MHZ_MULTIPLIER*/;
	                r6 /= (uint32_t)12/*SYNC_HW_STEP_MULTIPLIER*/ * (uint32_t)27/*SYNC_DPLL_TIME_BASE_MHZ*/;
	                divCount = r6 & 0xFFFFFFFE; /* make value an integer multiple of 2 */
	                /* check useful limit */
	                if (divCount > SYNC_DPLL_DIV_COUNT_LIM_HDMI)
	                {
	                    divCount = (uint32_t)SYNC_DPLL_DIV_COUNT_LIM_HDMI;
	                    //->loc_23435d14
	                }
	                else if (divCount < SYNC_DPLL_MIN_DIV_COUNT)
	                {
	                    divCount = (uint32_t)SYNC_DPLL_MIN_DIV_COUNT;
	                }
	            }
	            else
	            {
	            	//loc_23435d10
	            	divCount = (uint32_t)SYNC_DPLL_DIV_COUNT_LIM_HDMI;
	            }
	            //loc_23435d14
	            /* toggle direction */
	            if (stcPcrDeltaDiff2 > 0) /* use stcPcrDeltaDiff2 for the case of low deviation */
	            {
	                bData_23492740/*increase*/ = 0/*SYNC_DPLL_DECREASE_SPEED*/;
	            }
	            else
	            {
	            	bData_23492740/*increase*/ = 1/*SYNC_DPLL_INCREASE_SPEED*/;
	            }
	            /* set divider to calculated value */
	            syncSetDivCountValues();
	        } //if (stcPcrDeltaVariance < 100000L) //SYNC_MAX_PCR_VARIANCE)
	        else
	        {
	        	//loc_23435d40
	        	bData_23492740/*increase*/ = 0/*SYNC_DPLL_DECREASE_SPEED*/;

	        	syncSetDivCountValues();
	        }
	        //loc_23435d38
	        syncState = 13; //SYNC_DPLL_STATE_ADJUSTING;
	        //->loc_23435aac
	    }
	    else
	    {
	    	//loc_23435d48
	        /* valid PCR received */
	        if (Data_23492750/*syncResetCounter*/ < 5/*SYNC_RESET_COUNTER_VALUE*/)
	        {
	        	Data_23492750/*syncResetCounter*/++;
	        }

	        /* in sync again */
	        if (Data_23492750/*syncResetCounter*/ == 5/*SYNC_RESET_COUNTER_VALUE*/)
	        {
	            Data_23492748 = 1;
	        }

	        if (stcPcrDeltaVariance < 100000L/*SYNC_MAX_PCR_VARIANCE*/)
	        {
	            /* 4 cases have to be distinguished */
	            if (stcPcrDeltaDiff < -4)
	            {   /* STC is far slower than PCR, we make it faster */
	                regFactor = 4;
	                //->loc_23435e80
	                syncDpllFaster(regFactor);
	                //->loc_23435aac
	            }
	            //0x23435d8c
	            else if (stcPcrDeltaDiff2 < 0)
	            {   /* STC is a bit slower than PCR, should we make it faster ? */
	                if (stcPcrDiff < 0 )
	                {   /* stc is also behind pcr => we make it faster */
	                	//0x23435dac
	                    regFactor = 2;
	                    if (stcPcrDiff < -2700)
	                    {
	                        regFactor = 4;
	                        //->loc_23435e7c
	                    }
	                    else if (stcPcrDiff < -27000)
	                    {
	                        regFactor = 8;
	                        //->loc_23435e7c
	                    }
	                    syncDpllFaster(regFactor);
		                //->loc_23435aac
	                }
	                //loc_23435aac
	            }
	            //loc_23435dd8
	            else if (stcPcrDeltaDiff > 4)
	            {   /* STC is far faster than PCR, we make it slower */
	                regFactor = 4;

	                syncDpllSlower(regFactor);
	                //->loc_23435aac
	            }
	            //0x23435de8
	            else if (stcPcrDeltaDiff2 > 0)
	            {   /* STC is a bit faster than PCR, should we make it slower ? */
	                if (stcPcrDiff > 0 )
	                {   /* stc is also ahead of pcr => we make it slower */
	                	//0x23435e0c
	                    regFactor = 2;
	                    if (stcPcrDiff > 2700)
	                    {
	                        regFactor = 4;
	                    }
	                    else if (stcPcrDiff > 27000)
	                    {
	                        regFactor = 8;
	                    }
	                    //->loc_23435ef0
	                    syncDpllSlower(regFactor);
	                    //->loc_23435aac
	                }
	                //loc_23435aac
	            }
	            //loc_23435aac
	            /* else
	                (stcPcrDeltaDiff == 0)
	                do nothing */
	        } //if (stcPcrDeltaVariance < 100000L/*SYNC_MAX_PCR_VARIANCE*/)
	        else
	        {
	        	//loc_23435e38
	            /* 3 cases have to be distinguished */
	            if (stcPcrDeltaDiff < 0)
	            {   /* STC is slower than PCR, we make it faster */
	                if (stcPcrDiff < -270 )
	                {   /* stc is also behind pcr => we make it faster */
	                    regFactor = 2;
	                    if (stcPcrDiff < -2700)
	                    {
	                    	//loc_23435dc8
	                        regFactor = 4;
	                        //->loc_23435e7c
	                    }
	                    else if (stcPcrDiff < -13500)
	                    {
	                    	//loc_23435dd0
	                        regFactor = 8;
	                    }
	                    //loc_23435e7c
	                    syncDpllFaster(regFactor);
	                }
	                //loc_23435aac
	            }
	            //loc_23435e88
	            else if (stcPcrDeltaDiff > 0)
	            {   /* STC is faster than PCR, we make it slower */
	                if (stcPcrDiff > 270 )
	                {   /* stc is also ahead of pcr => we make it slower */
	                    regFactor = 2;
	                    if (stcPcrDiff > 2700)
	                        regFactor = 4;
	                    else if (stcPcrDiff > 13500)
	                        regFactor = 8;
	                    syncDpllSlower(regFactor);
	                }
	            }
	            else
	            {   /* STC is about same speed as PRC, we regulate according
	                   to the absolute time difference */
	                regFactor = 1;
	                if (stcPcrDiff < -270 )
	                {   /* stc is behind pcr => we make it faster */
	                	syncDpllFaster(regFactor);
	                }
	                if (stcPcrDiff > 270 )
	                {   /* stc is ahead of pcr => we make it slower */
	                	syncDpllSlower(regFactor);
	                }
	            }
	        }
	    }
	}
	//loc_23435aac
	return;
}


/* 23435efc - todo */
void sync_SetStcRegulation(int a, int enableStcRegulation)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sync_SetStcRegulation (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (enableStcRegulation != 0)
	{
		syncStcRegulation = 1;
	}
	else
	{
		syncStcRegulation = 0; //r5
	}

	Data_23492748 = 0; //r5

	memset(&avStcPcrDiff[0], 0, sizeof(avStcPcrDiff));
	memset(&avStcPcrDeltaDiff[0], 0, sizeof(avStcPcrDeltaDiff));

	averageFill = 0; //r5
	averageIndex = 0; //r5
	currentPcr = 0; //r5
	currentStc = 0; //r5
	previousPcr = -1;
	previousStc = -1;
	Data_23492750 = 5;
	syncState = 0; //r5

	OS_EXIT_CRITICAL();
}


/* 23435f74 - todo */
uint32_t sub_23435f74(uint8_t* r5)
{
#if 0
	console_send_string("sub_23435f74 (todo.c): TODO\r\n");
#endif

	uint32_t r4 = 0;
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif	
    
    OS_ENTER_CRITICAL();

	if (Data_23492748 != 1)
	{
		*r5 = r4 = 0;
		//->loc_23435fb4
	}
	else
	{
		//0x23435f9c
		*r5 = 1;
		r4 = syncGetStc(Data_2349274c) / 2;
	}
	//loc_23435fb4
	OS_EXIT_CRITICAL();

	return r4;
}


/* 23435fc4 / 23444018 - complete */
void sub_23435fc4()
{
#if 0
	console_send_string("sub_23435fc4 (todo.c): TODO\r\n");
#endif

	/* empty */
}


/* 23435fc8 / 2344401c - todo */
void sync_SetFd2to54Mhz(int enable)
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif

#if 0
	console_send_string("sync_SetFd2to54Mhz (todo.c): TODO\r\n");
#endif

	OS_ENTER_CRITICAL();

	if (enable != syncUseFd2as54Mhz)
	{
		if (enable == 0)
		{
			FREG(0xca00005c)[0] = 0;
			FREG(0xca000028)[0] = 0;
			//->loc_23436050
		}
		else
		{
			clkpwr_SetFd2audio_ResetFd2(0);

			//FREG_CLKPWR_SetFd2audio_Fd2rest
			int val = 0;
			FREG(0xca00005c)[0] = (FREG(0xca00005c)[0] & ~0x3ff00000) | val; //FD2AUDIO:FD2REST

			//FREG_CLKPWR_SetFd2audio_Fd2modulo
			val = 0xd800;
			FREG(0xca00005c)[0] = (FREG(0xca00005c)[0] & ~0x3ff00) | val; //FD2AUDIO:FD2MODULO

			//FREG_CLKPWR_SetFd2audio_Fd2muxsel
			val = 0;
			FREG(0xca00005c)[0] = (FREG(0xca00005c)[0] & ~0x7f) | val; //FD2AUDIO:FD2MUXSEL

			clkpwr_SetFd2audio_ResetFd2(1);

			FREG(0xca000028)[0] = 0x33;
			FREG(0xca000050)[0] = (FREG(0xca000050)[0] & ~0xff000000); //FDPRESCALE
		}
		//loc_23436050
		syncUseFd2as54Mhz = enable;

		syncReset();
	}
	//loc_23436058
	OS_EXIT_CRITICAL();
}


/* 23436064 - complete */
void clkpwr_SetDpllconfig_PptCountReg(uint32_t a)
{
	uint32_t mask = 0x01FF0000UL; //(0x1ff << 16);
	a = (a << 16) & mask;

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~mask) | a; //DPLLCONFIG:PPT_COUNT_REG
}


/* 23436088 - complete */
void clkpwr_SetDpllconfig_IncFreqfd3(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_IncFreqfd3 (todo.c): TODO\r\n");
#endif

	a = (a << 13) & (1 << 13);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 13)) | a; //DPLLCONFIG:INC_FREQFD3
}


/* 234360a8 - complete */
void clkpwr_SetDpllconfig_EnDpllfd3(int a)
{
#if 0
	console_send_string("sub_234360e8 (todo.c): TODO\r\n");
#endif

	a = (a << 12) & (1 << 12);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 12)) | a; //DPLLCONFIG:EN_DPLLFD3
}


/* 234360c8 - complete */
void clkpwr_SetDpllconfig_IncFreqfd2(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_IncFreqfd2 (todo.c): TODO\r\n");
#endif

	a = (a << 9) & (1 << 9);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 9)) | a; //DPLLCONFIG:INC_FREQFD2
}


/* 234360e8 - complete */
void clkpwr_SetDpllconfig_EnDpllfd2(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_EnDpllfd2 (todo.c): TODO\r\n");
#endif

	a = (a << 8) & (1 << 8);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 8)) | a; //DPLLCONFIG:EN_DPLLFD2
}


/* 23436108 - complete */
void clkpwr_SetDpllconfig_IncFreqfd1(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_IncFreqfd1 (todo.c): TODO\r\n");
#endif

	a = (a << 5) & (1 << 5);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 5)) | a; //DPLLCONFIG:INC_FREQFD1
}


/* 23436128 - complete */
void clkpwr_SetDpllconfig_EnDpllfd1(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_EnDpllfd1 (todo.c): TODO\r\n");
#endif

	a = (a << 4) & (1 << 4);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 4)) | a; //DPLLCONFIG:EN_DPLLFD1
}


/* 23436148 - complete */
void clkpwr_SetDpllconfig_EnPptHdmi(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_EnPptHdmi (todo.c): TODO\r\n");
#endif

	a = (a << 3) & (1 << 3);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 3)) | a; //DPLLCONFIG:EN_PPT_HDMI
}


/* 23436168 - complete */
void clkpwr_SetDpllconfig_IncPptHdmi(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_IncPptHdmi (todo.c): TODO\r\n");
#endif

	a = (a << 2) & (1 << 2);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 2)) | a; //DPLLCONFIG:INC_PPT_HDMI
}


/* 23436188 - complete */
void clkpwr_SetDpllconfig_IncFreqhdmi(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_IncFreqhdmi (todo.c): TODO\r\n");
#endif

	a = (a << 1) & (1 << 1);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 1)) | a; //DPLLCONFIG:INC_FREQHDMI
}


/* 234361a8 - complete */
void clkpwr_SetDpllconfig_EnDpllhdmi(int a)
{
#if 0
	console_send_string("clkpwr_SetDpllconfig_EnDpllhdmi (todo.c): TODO\r\n");
#endif

	a = (a << 0) & (1 << 0);

	*FREG(0xca00004c) = (*FREG(0xca00004c) & ~(1 << 0)) | a; //DPLLCONFIG:EN_DPLLHDMI
}


/* 23436218 - complete */
void clkpwr_SetFd2audio_ResetFd2(int a)
{
#if 0
	console_send_string("clkpwr_SetFd2audio_ResetFd2 (todo.c): TODO\r\n");
#endif

	uint32_t mask = 0x80000000;
	a = (a << 31) & mask;

	*FREG(0xca00005c) = (*FREG(0xca00005c) & ~mask) | a; //FD2AUDIO:reset_FD2
}


/* 23436238 - todo */
uint64_t syncGetStc(int a)
{
#if 0
	console_send_string("syncGetStc (todo.c): TODO\r\n");
#endif

	uint64_t stc;
	uint64_t r2;
	uint64_t r0;
	uint64_t base;
	uint64_t extension;

	if (a == 0)
	{
		r2 = FREG(0xc8000124)[0]; //TSD01_CURRENT_STC_LOWER
		r0 = FREG(0xc8000128)[0]; //TSD01_CURRENT_STC_UPPER
		stc = (r0 << 32) | r2;
	}
	else
	{
		r2 = FREG(0xc8800124)[0];
		r0 = FREG(0xc8800128)[0];
		stc = (r0 << 32) | r2;
	}

    base = stc & (uint64_t)0xFFFFFFFFFFFFFE00ULL;
    base >>= 9;
    /* bring base to same resolution as extension */
    base *= 300; //SYNC_EXTENSION_RESOLUTION;
    /* only save PCR extension */
    extension = stc & 0x1FF;
    stc = base + extension;

	return stc;
}


/* 23436280 - todo */
void syncReloadPcr(int a)
{
#if 0
	console_send_string("syncReloadPcr (todo.c): TODO\r\n");
#endif

	memset(&avStcPcrDiff[0], 0, sizeof(avStcPcrDiff));
	memset(&avStcPcrDeltaDiff[0], 0, sizeof(avStcPcrDeltaDiff));

	averageFill = 0;
	averageIndex = 0;
	currentPcr = 0;
	currentStc = 0;
	previousPcr = -1;
	previousStc = -1;

	if (a != 0)
	{
		FREG(0xC8800124)[0] = 0; //TSD23_CURRENT_STC_LOWER
		FREG(0xC8800128)[0] = 0; //TSD23_CURRENT_STC_UPPER
		FREG(0xC8800134)[0] = 1; //TSD23_LOAD_PCR
	}
	else
	{
		FREG(0xc8000124)[0] = 0; //TSD01_CURRENT_STC_LOWER
		FREG(0xc8000128)[0] = 0; //TSD01_CURRENT_STC_UPPER
		FREG(0xc8000134)[0] = 1; //TSD01_LOAD_PCR
	}
}


