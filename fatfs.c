
#include <string.h>
#include "data.h"
#include "usb_msd.h"
#include "sub_2345609c.h"


typedef struct
{
	int fill_0[3]; //0
	uint8_t fill_0xc; //0xc = 12
	uint8_t bData_0xd; //0xd = 13
	uint16_t fill_0xe; //0xe = 14
	uint8_t bData_0x10; //0x10 = 16
	int fill_0x14[107]; //0x14
	uint16_t fill_0x1c0; //0x1c0 = 448
	uint8_t bData_0x1c2; //0x1c2
} Struct_234920d8;


//234920d4 /  / 234c0530
void* Data_234920d4 = 0; //234920d4 +0 /  / 234c0530
void* Data_234920d8 = 0; //234920d8 +4 /  / 234c0534
int Data_234920dc = 0; //234920dc +8

struct
{
	int fill_0[128]; //0
	//0x200
} Data_235af2cc; //235af2cc /  / 2361E8A4

typedef struct 
{
	uint8_t bData_0; //0
	uint8_t bData_1; //1
	uint8_t bData_2; //2
	uint8_t arData_3[0x100]; //size????

} Struct_235af4cc;

Struct_235af4cc Data_235af4cc; //235af4cc

typedef struct
{
	uint8_t bIsFAT32; //0
	uint8_t fill_1; //1
	uint16_t wData_2; //2
	uint16_t fill_4; //4
	uint16_t wBytsPerSec; //6
	int Data_8; //8
	int dwRootCluster; //0xc = 12
	int Data_0x10; //0x10
	int Data_0x14; //0x14
	int Data_0x18; //0x18 = 24
	int Data_0x1c; //0x1c = 28
	int Data_0x20; //0x20
	int Data_0x24; //0x24
	int dwBytesPerClus; //0x28
	int fill_0x2c; //0x2c
	int Data_0x30; //0x30
	int Data_0x34; //0x34
	int (*read)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //0x38
	int (*write)(void* h, uint32_t dwStartBlockLo, void* pBuffer, uint16_t wBlockCount); //0x3c
	int fill_0x40[2]; //0x40
	void (*Data_0x48)(); //0x48
	USB_MSD_Device* Data_0x4c; //0x4c
	//0x50 = 80
} Struct_235af5d0;

Struct_235af5d0 Data_235af5d0[1]; //235af5d0 /  / 2361eba8

struct
{
	int fill_0[430]; //0
	//0x6b8
} Data_235af620; //235af620 /  / 2361ebf8


static void get_bytes(int offset, uint8_t* pbBuffer, uint16_t numBytes);
static uint16_t get_word(int offset);
static uint8_t get_byte(uint16_t offset);
int sub_23416ae0(uint16_t offset);
int sub_23416b08(uint16_t offset);
int sub_23416b28(uint16_t offset);
static int sub_234150c8(uint16_t offset);



/* 234145d0 - complete */
static uint32_t get_dword(int offset)
{
#if 0
	console_send_string("get_dword (todo.c): TODO\r\n");
#endif

	uint8_t* addr = Data_234920d8;

	return (*(addr + offset + 3) << 24) + 
		(*(addr + offset + 2) << 16) + 
		(*(addr + offset + 1) << 8) + 
		*(addr + offset);
}


/* 234148c4 - todo */
int sub_234148c4(Struct_235af5d0* r8, int r7, uint32_t sb, int* r6)
{
#if 0
	console_send_string("sub_234148c4 (todo.c): TODO\r\n");
#endif

	uint16_t r5 = r8->wData_2;
	uint32_t r4 = sb / r5;
	int r0 = (r5 * r4);
	sb -= r0;

	if (r6 == 0)
	{
		//->loc_23414918
		for (uint32_t r5 = 0; r5 < r4; r5++)
		{
			//loc_23414904
			r7 = sub_234147d8(r8, r7);
		}
		//->loc_23414960
	}
	else
	{
		//loc_23414924
		uint32_t r5 = 0;

		if (r6[0] != 0)
		{
			//0x23414930
			if (r6[0] < r4)
			{
				r7 = r6[4];
				r5 = r6[0] - 1;
			}
			//->loc_23414958
		}
		//loc_23414958
		for (; r5 < r4; r5++)
		{
			//loc_23414940
			r6[0] = r4;
			r6[1] = r7;

			r7 = sub_234147d8(r8, r7);
		}
	}
	//loc_23414960
	if (r7 != 1)
	{
		//0x23414968

		//TODO
	}
	//loc_234149a0
	return r7;
}


/* 23414cfc /  / 2341c710 - todo */
int fatfs_volume_init(int a)
{
#if 0
	console_send_string("fatfs_volume_init (todo.c): TODO\r\n");
#endif

	uint8_t BS_FilSysType[9/*size???*/];
	uint8_t BS_VolLab[14]; //sp_0x32
	uint16_t BPB_FSInfo; //sp_0x30
	int BPB_RootClus; //sp_0x2c
	int BPB_FATSz32; //sp_0x28
	int BPB_HiddSec; //sp_0x24
	uint16_t BPB_FATSz16; //sp_0x20
	uint16_t BPB_RootEntCnt; //sp_0x1e
	uint8_t BPB_NumFATs; //sp_0x1c
	uint16_t BPB_RsvdSecCnt; //sp_0x1a
	uint16_t BPB_SecPerClus; //sp_0x18
	uint16_t BPB_BytsPerSec; //sp_0x16
	uint8_t BS_OEMName[9]; //sp_0xd
	uint8_t partitionType; //sp_0xc
	int sp8;
	int sp4;

	int r5;
	int r5_;
	int fp;
	int fp_;
	int x;

	int r6 = 0;
//	int sl = 0;

	Struct_235af5d0* r4 = &Data_235af5d0[0];

	Data_234920dc = 0; //r6

	(r4->read)(r4->Data_0x4c, 0, Data_234920d8, 1);

	int sb = 510; //0x1fe; //BS_55AA
	int r0 = get_word(sb/*0x1fe*/);
	int r8 = 0xaa55;
	if (r0 != /*0xaa55*/r8)
	{
		//loc_23415024
		return 3;
	}
	//0x23414d48
	partitionType = ((Struct_234920d8*)Data_234920d8)->bData_0x1c2;
	if ((partitionType == 0x0c/*FAT32 LBA*/) || (partitionType == 0x0b/*FAT32 CHS*/))
	{
		r6 = get_dword(0x1c6);
		//->loc_23414e2c
	}
	else
	{
		//loc_23414d70
		if (0 != get_dword(0x1c)) //Number of hidden sectors. (i.e. the LBA of the beginning of the partition.)
		{
			//loc_23415024
			return 3;
		}
		r5 = get_word(0x11); //Number of root directory entries (must be set so that the root directory occupies entire sectors). 
		fp = get_word(0x16); //Number of sectors per FAT. FAT12/FAT16 only. 
		x = get_word(0x13); //The total sectors in the logical volume. If this value is 0, it means there are more than 65535 sectors in the volume, and the actual count is stored in the Large Sector Count entry at 0x20. 
		//if ((r5 | fp | x) != 0)
		if (((r5 != 0) || (fp != 0) || (x != 0)) != 0)
		{
			//loc_23415024
			return 3;
		}
		//0x23414dac
		r5_ = ((Struct_234920d8*)Data_234920d8)->bData_0xd; //Number of sectors per cluster. 
		sp4 = get_word(0x0e); //Number of reserved sectors. The boot record sectors are included in this value.

		fp_ = ((Struct_234920d8*)Data_234920d8)->bData_0x10; //Number of File Allocation Tables (FAT's) on the storage media. Often this value is 2. 
		sp8 = get_dword(0x20); //Large sector count. This field is set if there are more than 65535 sectors in the volume, resulting in a value which does not fit in the Number of Sectors entry at 0x13. 

		uint32_t r0 = get_dword(0x24); //Sectors per FAT. The size of the FAT in sectors. 
		uint32_t r1 = fp_ * r0 + sp4;
		uint32_t r0_ = (sp8 - r1) / r5_;
		if (r0_ < 0xfff5)
		{
			//loc_23415024
			return 3;
		}
		//0x23414e00
		get_bytes(0x52, &BS_FilSysType[0], 8); //System identifier string. Always "FAT32   ". The spec says never to trust the contents of this string for any use. 

		BS_FilSysType[8] = 0; //sl

		if (0 != strncmp((char*)&BS_FilSysType[0], "FAT32", 5))
		{
			//loc_23415024
			return 3;
		}
		//loc_23414e2c
	}
	//loc_23414e2c
	Data_234920dc = r6;

	(r4->read)(r4->Data_0x4c, r6, Data_234920d8, 1);

	if (get_word(sb/*0x1fe*/) != /*0xaa55*/r8)
	{
		//loc_23415024
		return 3;
	}
	//0x23414e58
//	uint8_t* r5 = &sp_0xc; //sp_0x32

	BS_OEMName[8]/*sp_0x15*/ = 0; //sl

	get_bytes(0x03, &BS_OEMName[0], 8);

	BPB_BytsPerSec = get_word(0x0b); //Bytes Per Sector
	BPB_RsvdSecCnt = get_word(0x0e); //Number of Reserved Sectors	

	BPB_NumFATs = ((Struct_234920d8*)Data_234920d8)->bData_0x10; //Number of FATs

	BPB_RootEntCnt = get_word(0x11);
	BPB_FATSz16 = get_word(0x16);

	BPB_HiddSec = get_dword(0x1c);
	if (BPB_HiddSec == 0)
	{
		BPB_HiddSec = r6;
	}

	BPB_FATSz32 = get_dword(0x24); //Sectors Per FAT
	BPB_RootClus = get_dword(0x2c); //Root Directory First Cluster
	BPB_FSInfo = get_word(0x30);

	BS_VolLab[11]/*sp_0x3d*/ = 0; //sl

	if ((partitionType == 0x0f/*Extended Partition*/) ||
			(((Struct_234920d8*)Data_234920d8)->bData_0xd == 0))
	{
		//0x23414efc
		BPB_SecPerClus = get_word(0x18);
	}
	else
	{
		//loc_23414f04
		BPB_SecPerClus = ((Struct_234920d8*)Data_234920d8)->bData_0xd;
	}

	get_bytes(0x47, &BS_VolLab[0], 11);

	get_bytes(0x52, &BS_FilSysType[0], 8);

	BS_FilSysType[8] = 0;
	r4->wData_2 = BPB_SecPerClus;

	int BPB_FATSz = BPB_FATSz16;
	/* Number of sectors occupied by a FAT. 
		This field is used for only FAT12/16 volumes. 
		On the FAT32 volumes, it must be an invalid value 0 and BPB_FATSz32 is used instead. 
	*/
	if (BPB_FATSz == 0) 
	{
		BPB_FATSz = BPB_FATSz32;
		r4->bIsFAT32 = 1;
		r4->dwRootCluster = BPB_RootClus;
	}
	else
	{
		r4->bIsFAT32 = 0; //sl
		r4->dwRootCluster = 1;
	}

	int RootDirSectors = (((32 * BPB_RootEntCnt) + BPB_BytsPerSec) - 1) / BPB_BytsPerSec;

	r4->Data_0x18 = BPB_FATSz;

	r4->Data_0x1c = (BPB_BytsPerSec / 4) * BPB_FATSz;

	r4->Data_0x10 = BPB_HiddSec + BPB_RsvdSecCnt;

	if (BPB_NumFATs == 2)
	{
		r4->Data_0x14 = r4->Data_0x10 + BPB_FATSz;
	}
	else
	{
		r4->Data_0x14 = 0; //sl
	}
	//0x23414fa0
	int r1 = (BPB_HiddSec + BPB_RsvdSecCnt);
	int FatSectors = BPB_NumFATs * BPB_FATSz;
	int RootDirStartSector = FatSectors + r1;
	r4->Data_0x24 = RootDirStartSector + RootDirSectors; //DataStartSector 
	r4->Data_8 = RootDirSectors;
	r4->dwBytesPerClus = BPB_SecPerClus * BPB_BytsPerSec;
	r4->wBytsPerSec = BPB_BytsPerSec;

	if (r4->bIsFAT32 == 0)
	{
		r4->Data_0x20 = 0; //sl
		r4->Data_0x30 = 0; //sl
		r4->Data_0x34 = 0; //sl
		//->loc_23415048
	}
	else
	{
		//0x23414ff0
		r4->Data_0x20 = BPB_FSInfo + r6;
		Data_234920dc = r4->Data_0x20;

		// Read the FSInfo Sector
		(r4->read)(r4->Data_0x4c, Data_234920dc, 
			Data_234920d8, 1);

		if (get_word(sb/*0x1fe*/) != /*0xaa55*/r8)
		{
			//loc_23415024
			return 3;
		}
		//loc_23415030
		r4->Data_0x30 = get_dword(0x1e8); //FSI_Free_Count
		r4->Data_0x34 = get_dword(0x1ec); //FSI_Nxt_Free
	}
	//loc_23415048
	return 0;
}


/* 23415074 - todo */
int sub_23415074(uint16_t offset)
{
#if 0
	console_send_string("sub_23415074 (todo.c): TODO\r\n");
#endif

	if ((get_byte(offset) != 0x00) &&
		(get_byte(offset) != 0xe5) &&
		(get_byte(offset + 11) != 0x08) &&
		((get_byte(offset + 11) & 0x06) == 0))
	{
		return 0;
	}

	return 1;
}


/* 234150c8 - todo */
int sub_234150c8(uint16_t offset)
{
#if 0
	console_send_string("sub_234150c8 (todo.c): TODO\r\n");
#endif

	if ((get_byte(offset + 11) != 0x0f) &&
		(get_byte(offset) != 0x00) &&
		(get_byte(offset) != 0xe5) &&
		(get_byte(offset + 11) != 0x08) &&
		((get_byte(offset + 11) & 0x06) == 0))
	{
		return 1;
	}

	return 0;
}


/* 23415178 - complete */
void sub_23415178(uint16_t offset)
{
#if 0
	console_send_string("sub_23415178 (todo.c): TODO\r\n");
#endif

	uint16_t r0;
	uint8_t r5 = get_byte(offset);

	if (r5 == 0xe5)
	{
		return;
	}

	offset = offset + 1;

	if ((r5 & 0x040) != 0)
	{
		memset(&Data_235af4cc.arData_3[0], 0, 0x100);

		Data_235af4cc.bData_0 = 1;
		Data_235af4cc.bData_2 = r5;
	}
	//loc_234151bc
	Data_235af4cc.bData_1 = ((r5 & 0x0f) - 1) * 13;
	if (Data_235af4cc.bData_1 >= 0xf3)
	{
		return;
	}

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1], 1);

	offset = offset + 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 1], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 2], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 3], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 4], 1);

	offset += 5;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 5], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 6], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 7], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 8], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 9], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 10], 1);

	offset += 4;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 11], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &Data_235af4cc.arData_3[Data_235af4cc.bData_1 + 12], 1);
}


/* 23415488 - todo */
void sub_23415488(Struct_235af5d0* a)
{
#if 0
	console_send_string("sub_23415488 (todo.c): TODO\r\n");
#endif

	uint8_t sp4[24]; //size???

	int sl;
	int sb = 0;
	int r6 = 0; 

	Data_235af4cc.bData_0 = 0;

	do
	{
		//loc_234154a4
		sl = sub_234148c4(a, a->dwRootCluster, sb++, 0);
		if (sl == -1)
		{
			break;
		}
		//0x234154c8
		uint16_t r5 = 0;
		for (uint8_t r7 = 0; r7 <= 15; r5 += 32, r7++)
		{
			//loc_234154d0
			int r0 = sub_23416ae0(r5);
			if (r0 != 0)
			{
				sub_23415178(r5);
				//->loc_234155fc
				//continue;
			}
			else
			{
				//loc_234154ec
				r0 = sub_23415074(r5);
				if (r0 != 0)
				{
					Data_235af4cc.bData_0 = 0;
					//->loc_23415580
					r6 = 0;
					//->loc_234155fc
					continue;
				}
				else
				{
					//0x23415500
#if 1
					int r4 = r5 + 11;
					uint8_t r8 = r6;
					if ((get_byte(r4) != 0x0f) &&
						(get_byte(r5) != 0) &&
						(get_byte(r5) != 0xe5) &&
						(get_byte(r4) != 0x08) &&
						((get_byte(r4) & 0x06) == 0) &&
						(r8 != 0))
#else	
					if ((sub_234150c8(r5) != 0) && (r6 != 0))
#endif
					{
						//0x23415560
						r0 = sub_23416b28(r5);
						if (r0 == 0)
						{
							//0x23415570
							r0 = sub_23416b08(r5);
							if (r0 == 0)
							{
								//->loc_2341561c
								break;
							}
							//loc_23415580
						}
						//loc_23415580
						r6 = 0;
						//->loc_234155fc
						continue;
					}
					//loc_23415588
					r0 = sub_234150c8(r5);
					if (r0 == 0)
					{
						//->loc_234155fc
						continue;
					}
					//0x23415598
					r6 = 0;
					
					r0 = sub_23416b28(r5);
					if (r0 == 0)
					{
						//0x234155ac
						r0 = sub_23416b08(r5);
						if (r0 == 0)
						{
							//->loc_2341561c
							break;
						}
						//loc_234155bc
					}
					//loc_234155bc
					for (uint16_t r4 = 0; r4 < 11; r4++)
					{
						//loc_234155c4
						sp4[r4 + 1] = 0;
						sp4[r4] = get_byte(r4 + r5);
					}
					//0x234155ec
					if (Data_235af4cc.bData_0 != 0)
					{
						Data_235af4cc.bData_0 = 0;
					}
					//loc_234155fc
				}
			}
		} //for (uint8_t r7 = 0; r7 <= 15; r5 += 32, r7++)
	} 
	while (sl != -1);
	//loc_2341561c
}


/* 23415f44 /  / 2341d958 - complete */
int fatfs_volume_add_usb_device(Struct_23415f44* r4)
{
#if 0
	console_send_string("fatfs_volume_add_usb_device (todo.c): TODO\r\n");
#endif

	memset(Data_235af5d0, 0, sizeof(Data_235af5d0));

	Data_235af5d0[0].read = r4->read;
	Data_235af5d0[0].write = r4->write;
	Data_235af5d0[0].Data_0x4c = r4->Data_0x18; 
	Data_235af5d0[0].Data_0x48 = r4->Data_20;

	Data_234920d8 = &Data_235af2cc;

	if (Data_234920d4 == 0)
	{
		Data_234920d4 = OSSemCreate(1);
	}

	memset(&Data_235af620, 0, sizeof(Data_235af620));

    return 0;
}


/* 23415fb4 /  / 2341d9c8 - complete */
int fatfs_init(void)
{
#if 0
	console_send_string("fatfs_init (todo.c): TODO\r\n");
#endif

	fatfs_wait_semaphore();

	if (0 != fatfs_volume_init(0))
	{
		OSSemPost(Data_234920d4);

		return 0xff;
	}
	else
	{
		//loc_23415fe0
		sub_23415488(&Data_235af5d0[0]);

		OSSemPost(Data_234920d4);

		return 0;
	}
}


/* 23415ff8 /  / 2341da0c - complete */
int fatfs_volume_remove_usb_device(int r4)
{
#if 0
	console_send_string("fatfs_volume_remove_usb_device (todo.c): TODO\r\n");
#endif

	fatfs_wait_semaphore();

	Data_235af5d0[r4].Data_0x4c = 0;

	OSSemPost(Data_234920d4);

	return 0;
}


/* 234168d0 /  / 2341e2e4 - complete */
USB_MSD_Device* fatfs_volume_get_usb_device(int a)
{
#if 0
	console_send_string("fatfs_volume_get_usb_device (todo.c): TODO\r\n");
#endif

	Struct_235af5d0* r4_ = &Data_235af5d0[a];

	fatfs_wait_semaphore();

	USB_MSD_Device* r4 = r4_->Data_0x4c;

	OSSemPost(Data_234920d4);

	return r4;
}


/* 23416a38 /  / 2341e44c - complete */
int fatfs_wait_semaphore(void)
{
#if 0
	console_send_string("fatfs_wait_semaphore (todo.c): TODO\r\n");
#endif

	uint8_t err;

	OSSemPend(Data_234920d4, 0, &err);

	return err;
}


/* 23416a58 - complete */
uint8_t get_byte(uint16_t offset)
{
#if 0
	console_send_string("get_byte (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;

	return *(addr + offset);
}


/* 23416a68 - complete */
uint16_t get_word(int offset)
{
#if 0
	console_send_string("get_word (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;

	uint16_t w = *(addr + offset + 1);
	w += (*(addr + offset) << 8);

	return w;
}


/* 23416a88 /  / 2341ce9c - complete */
void get_bytes(int offset, uint8_t* pbBuffer, uint16_t numBytes)
{
#if 0
	console_send_string("get_bytes (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;

	addr += offset;

	while (numBytes--)
	{
		void* p = pbBuffer + 1;
		*pbBuffer = *addr++;
		pbBuffer = p;
	}

}


/* 23416ae0 - complete */
int sub_23416ae0(uint16_t offset)
{
#if 0
	console_send_string("sub_23416ae0 (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;
	uint8_t r2 = 0x0f;

	offset += 11;

	return ((r2 & ~(*(addr + offset))) == 0)? 1: 0;
}


/* 23416b08 - todo */
int sub_23416b08(uint16_t offset)
{
#if 0
	console_send_string("sub_23416b08 (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;

	offset += 11;

	if (0x20 & *(addr + offset))
	{
		return 1;
	}

	return 0;
}


/* 23416b28 - complete */
int sub_23416b28(uint16_t offset)
{
#if 0
	console_send_string("sub_23416b28 (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;

	offset += 11;

	if (0x10 & *(addr + offset))
	{
		return 1;
	}

	return 0;
}


