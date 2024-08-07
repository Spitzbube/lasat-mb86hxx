/*****************************************************************************************
 *
 * FILE NAME          : MxL603_OEM_Drv.c
 *
 * AUTHOR             : Mahendra Kondur
 *
 * DATE CREATED       : 12/23/2011
 *
 * DESCRIPTION        : This file contains I2C driver and Sleep functins that
 *                      OEM should implement for MxL603 APIs
 *
 *****************************************************************************************
 *                Copyright (c) 2011, MaxLinear, Inc.
 ****************************************************************************************/
#include "sys_types.h"
#include "sys_define.h"
#include "mtos_printk.h"
#include "mtos_misc.h"
#include "MxL603_OEM_Drv.h"
#include "mt_fe_common.h"
#include "fe_dd3k_def.h"




#if (DEMODE_TYPE == DEMOD_DS3K)

extern MT_FE_RET MDrv_IIC_Write(U8 u8SlaveID, U8 *pu8Addr, U8 *pu8Buf);
extern MT_FE_RET MDrv_IIC_Read(U8 u8SlaveID, U8 *pu8Addr,  U8 *pu8Buf);

#endif

/*------------------------------------------------------------------------------
--| FUNCTION NAME : MxLWare603_OEM_Sleep
--|
--| AUTHOR        : Dong Liu
--|
--| DATE CREATED  : 01/10/2010
--|
--| DESCRIPTION   : This function complete sleep operation. WaitTime is in ms unit
--|
--| RETURN VALUE  : None
--|
--|-------------------------------------------------------------------------------------*/

void MxLWare603_OEM_Sleep(UINT16 DelayTimeInMs)
{
  // OEM should implement sleep operation
#if (DEMODE_TYPE == DEMOD_DS3K)
    mtos_task_delay_ms(DelayTimeInMs);
#endif
}



/*----------------------------------------------------------------------------------------
--| FUNCTION NAME : MxLWare603_OEM_WriteRegister
--|
--| AUTHOR        : Brenndon Lee
--|
--| DATE CREATED  : 7/30/2009
--|
--| DESCRIPTION   : This function does I2C write operation.
--|
--| RETURN VALUE  : True or False
--|
--|-------------------------------------------------------------------------------------*/

MXL_STATUS MxLWare603_OEM_WriteRegister(UINT8 devId, UINT8 RegAddr, UINT8 RegData)
{
  // OEM should implement I2C write protocol that complies with MxL603 I2C
  // format.

  // 8 bit Register Write Protocol:
  // +------+-+-----+-+-+----------+-+----------+-+-+
  // |MASTER|S|SADDR|W| |RegAddr   | |RegData(L)| |P|
  // +------+-+-----+-+-+----------+-+----------+-+-+
  // |SLAVE |         |A|          |A|          |A| |
  // +------+---------+-+----------+-+----------+-+-+
  // Legends: SADDR (I2c slave address), S (Start condition), A (Ack), N(NACK),
  // P(Stop condition)

  MXL_STATUS status = MXL_FALSE;


/* If OEM data is implemented, customer needs to use OEM data structure related operation
   Following code should be used as a reference.
   For more information refer to sections 2.5 & 2.6 of MxL603_mxLWare_API_UserGuide document.

  UINT8 i2cSlaveAddr;
  UINT8 i2c_bus;
  user_data_t * user_data = (user_data_t *) MxL603_OEM_DataPtr[devId];

  if (user_data)
  {
    i2cSlaveAddr = user_data->i2c_address;           // get device i2c address
    i2c_bus = user_data->i2c_bus;                   // get device i2c bus

    sem_up(user_data->sem);                         // up semaphore if needed

    // I2C Write operation
    status = USER_I2C_WRITE_FUNCTION(i2cSlaveAddr, i2c_bus, RegAddr, RegData);

    sem_down(user_data->sem);                       // down semaphore
    user_data->i2c_cnt++;                           // user statistics
  }

*/

  /* If OEM data is not required, customer should treat devId as I2C slave Address */

    MS_U8 pArray[6];

    pArray[0] = RegAddr;
    pArray[1] = RegData;
#if (DEMODE_TYPE == DEMOD_DS3K)
   {
      if (MDrv_IIC_Write(devId, NULL, pArray) == 0)
      {
      	  MxLWare603_OEM_Sleep(1);
          return status =MXL_TRUE ;
  	  }
  	  else
  	  {

         mtos_printk("\ni2c write err\n");
         return status=MXL_FALSE;
  	  }
   }
#endif
   return status;
}

/*------------------------------------------------------------------------------
--| FUNCTION NAME : MxLWare603_OEM_ReadRegister
--|
--| AUTHOR        : Brenndon Lee
--|
--| DATE CREATED  : 7/30/2009
--|
--| DESCRIPTION   : This function does I2C read operation.
--|
--| RETURN VALUE  : True or False
--|
--|---------------------------------------------------------------------------*/

MXL_STATUS MxLWare603_OEM_ReadRegister(UINT8 devId, UINT8 RegAddr, UINT8 *DataPtr)
{
  // OEM should implement I2C read protocol that complies with MxL603 I2C
  // format.

  // 8 bit Register Read Protocol:
  // +------+-+-----+-+-+----+-+----------+-+-+
  // |MASTER|S|SADDR|W| |0xFB| |RegAddr   | |P|
  // +------+-+-----+-+-+----+-+----------+-+-+
  // |SLAVE |         |A|    |A|          |A| |
  // +------+-+-----+-+-+----+-+----------+-+-+
  // +------+-+-----+-+-+-----+--+-+
  // |MASTER|S|SADDR|R| |     |MN|P|
  // +------+-+-----+-+-+-----+--+-+
  // |SLAVE |         |A|Data |  | |
  // +------+---------+-+-----+--+-+
  // Legends: SADDR(I2c slave address), S(Start condition), MA(Master Ack), MN(Master NACK),
  // P(Stop condition)

  MXL_STATUS status = MXL_TRUE;

/* If OEM data is implemented, customer needs to use OEM data structure related operation
   Following code should be used as a reference.
   For more information refer to sections 2.5 & 2.6 of MxL603_mxLWare_API_UserGuide document.

  UINT8 i2cSlaveAddr;
  UINT8 i2c_bus;
  user_data_t * user_data = (user_data_t *) MxL603_OEM_DataPtr[devId];

  if (user_data)
  {
    i2cSlaveAddr = user_data->i2c_address;           // get device i2c address
    i2c_bus = user_data->i2c_bus;                   // get device i2c bus

    sem_up(user_data->sem);                         // up semaphore if needed

    // I2C Write operation
    status = USER_I2C_READ_FUNCTION(i2cSlaveAddr, i2c_bus, RegAddr, DataPtr);

    sem_down(user_data->sem);                       // down semaphore
    user_data->i2c_cnt++;                           // user statistics
  }

*/

  /* If OEM data is not required, customer should treat devId as I2C slave Address */

  UINT8 pArray[6];

  pArray[0] = 0xFB;
  pArray[1] = RegAddr;

#if (DEMODE_TYPE == DEMOD_DS3K)

  {

    if (MDrv_IIC_Read( devId, pArray, DataPtr) == 0)
    {
      return status = MXL_TRUE ;
    }
    else
    {
      mtos_printk("i2c read err\n");
      return status = MXL_FALSE;
    }
  }
#endif
  return status;
}

