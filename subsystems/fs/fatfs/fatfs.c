
#include <string.h>
#include "data.h"
#include "usb_msd.h"
#include "fatfs.h"


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


uint8_t Data_235ae7bc[0x100]; //235ae7bc, size???
uint8_t Data_235ae8bc[0x100]; //235ae8bc, size???
uint8_t Data_235ae9bc[0x100]; //235ae9bc, size???

Struct_235af620 Data_235aeabc; //235aeabc
Struct_235af620 Data_235aec14; //235aec14
Struct_235af620 Data_235aed6c; //235aed6c

typedef struct
{
	uint8_t bAttr; //0
	uint8_t bData_1; //1
	int Data_4; //4
	int Data_8; //8
	int Data_0xc; //12
	int Data_0x10; //16
	int fill_0x14[3]; //20
	int Data_0x20; //32 = 0x20
	int Data_0x24; //36 = 0x24
	int fill_0x28[3]; //40 = 0x28
	uint8_t bData_0x34; //0x34
	uint8_t bData_235af1a9; //0x35 = 235af1a9
	uint8_t fill_0x36[255]; //0x36
	uint8_t shortFileName[11]; //0x135 235af2a9
	uint8_t bData_0x140; //0x140
	int Data_235af2b8; //0x144 235af2b8
	uint32_t Data_235af2bc; //0x148 235af2bc
	int fill_0x14c[2]; //0x14c
	void* Data_235af2c8; //0x154 235AF2C8

} Struct_235af174;

Struct_235af174 Data_235af174; //235af174

struct
{
	int fill_0[128]; //0
	//0x200
} Data_235af2cc; //235af2cc /  / 2361E8A4

typedef struct 
{
	uint8_t valid; //0
	uint8_t offset; //1
	uint8_t entries; //2
	uint8_t bytes[0x100]; //3, size????

} FATFS_LFN;

FATFS_LFN fatfs_lfn; //235af4cc

typedef struct Struct_235af5d0
{
	uint8_t bIsFAT32; //0
	uint8_t fill_1; //1
	uint16_t wSectorsPerCluster; //2
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
	void* pDev; //0x4c
	//0x50 = 80
} Struct_235af5d0;

Struct_235af5d0 Data_235af5d0[1]; //235af5d0 -> 235af620 /  / 2361eba8

Struct_235af620 Data_235af620[5]; //235af620 -> 235AFCD8 /  / 2361ebf8

char Data_235afcd8[52]; //235AFCD8 
char Data_235afd0c[100]; //235afd0c +0x64
char Data_235afd70[0x100]; //235AFD70, size???

static void get_bytes(int offset, uint8_t* pbBuffer, uint16_t numBytes);
static uint16_t get_word(int offset);
static uint8_t get_byte(uint16_t offset);
int fatfs_is_lfn(uint32_t offset);
int fatfs_is_archive(uint32_t offset);
int fatfs_is_directory(uint32_t offset);
static int sub_234150c8(uint32_t offset);



/* 234145d0 - complete */
static uint32_t get_dword(uint16_t offset)
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


/* 234147d8 - todo */
int sub_234147d8(Struct_235af5d0* r5, uint32_t r4)
{
#if 0
	console_send_string("sub_234147d8 (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		r4 = 2;
	}

	uint32_t r6 = r4 >> 7;
	Data_234920dc = r5->Data_0x10 + r6;	

	(r5->read)(r5->pDev, Data_234920dc, Data_234920d8, 1);

#if 0
	{
		hex_dump("sub_234147d8", Data_234920d8, 512);		
	}
#endif

	r6 = 0 - r6;

	uint32_t r0_;
	uint32_t r0 = r4 + (r6 << 7);

#if 0
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_234147d8: r0=0x%x\r\n", r0);
        console_send_string(debug_string);
    }
#endif

	if (r5->bIsFAT32)
	{
		r0_ = get_dword((r0 & 0x3fff) * 4);
	}
	else
	{
		r0_ = get_word((r0 & 0x7fff) * 2);
	}

	r0_ &= 0xfffffff;

#if 0
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_234147d8: r0_=0x%x\r\n", r0_);
        console_send_string(debug_string);
    }
#endif

	if (r0_ == 0xfffffff) //-0xf0000001)
	{
		return -1;
	}

	return r0_;
}


/* 234148c4 - todo */
int sub_234148c4(Struct_235af5d0* r8, int r7, uint32_t sb, int* r6)
{
#if 0
	console_send_string("sub_234148c4 (todo.c): TODO\r\n");
#endif

#if 0
    {
        extern char debug_string[];
        sprintf(debug_string, "sub_234148c4: r7=%d, sb=%d, r6=%p\r\n", 
            r7, sb, r6);
        console_send_string(debug_string);
    }
#endif

	uint16_t r5 = r8->wSectorsPerCluster;
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
			if (r6[0] <= r4)
			{
				r7 = r6[1];
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
	if (r7 != -1)
	{
		//0x23414968
		uint32_t r1 = r8->Data_0x24;
		r1 += sb + (r7 - 2) * r8->wSectorsPerCluster;

		if (Data_234920dc != r1)
		{
			Data_234920dc = r1;

#if 0
			{
				extern char debug_string[];
				sprintf(debug_string, "sub_234148c4: r7=%d, Data_234920dc=%d\r\n", 
					r7, Data_234920dc);
				console_send_string(debug_string);
			}
#endif

			(r8->read)(r8->pDev, Data_234920dc, Data_234920d8, 1);
		}
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

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "fatfs_volume_init: a=%d\r\n", a);
        console_send_string(debug_string);
    }
#endif

	(r4->read)(r4->pDev, 0, Data_234920d8, 1);

#if 1
    {
		hex_dump("fatfs_volume_init (1)", Data_234920d8, 512);
    }
#endif

	int sb = 510; //0x1fe; //BS_55AA
	int r0 = get_word(sb/*0x1fe*/);
	int r8 = 0xaa55;
	if (r0 != /*0xaa55*/r8)
	{
		//loc_23415024
#if 0
		{
			extern char debug_string[];
			sprintf(debug_string, "fatfs_volume_init: r0=0x%x, r8=0x%x\r\n", r0, r8);
			console_send_string(debug_string);
		}
#endif

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

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "fatfs_volume_init: Data_234920dc=%d\r\n", Data_234920dc);
        console_send_string(debug_string);
    }
#endif

	(r4->read)(r4->pDev, r6, Data_234920d8, 1);

#if 1
    {
		hex_dump("fatfs_volume_init (2)", Data_234920d8, 512);
    }
#endif

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
	r4->wSectorsPerCluster = BPB_SecPerClus;

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
		(r4->read)(r4->pDev, Data_234920dc, 
			Data_234920d8, 1);

#if 1
		{
			hex_dump("fatfs_volume_init (3)", Data_234920d8, 512);
		}
#endif

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
int sub_23415074(uint32_t a)
{
#if 0
	console_send_string("sub_23415074 (todo.c): TODO\r\n");
#endif

	uint16_t offset = a;

	if ((get_byte(offset) != 0x00) &&
		(get_byte(offset) != 0xe5) &&
		(get_byte(offset + 11) != 0x08/*ATTR_VOLUME_ID*/) &&
		((get_byte(offset + 11) & 0x06/*ATTR_HIDDEN | ATTR_SYSTEM*/) == 0))
	{
		return 0;
	}

	return 1;
}


/* 234150c8 - todo */
int sub_234150c8(uint32_t offset)
{
#if 0
	console_send_string("sub_234150c8 (todo.c): TODO\r\n");
#endif

	if ((get_byte(offset + 11) != 0x0f) &&
		(get_byte(offset) != 0x00) &&
		(get_byte(offset) != 0xe5) &&
		(get_byte(offset + 11) != 0x08/*ATTR_VOLUME_ID*/) &&
		((get_byte(offset + 11) & 0x06/*ATTR_HIDDEN | ATTR_SYSTEM*/) == 0))
	{
		return 1;
	}

	return 0;
}


/* 23415130 /  / 2341cb44 - todo */
int get_first_cluster(int a)
{
#if 0
	console_send_string("get_first_cluster (todo.c): TODO\r\n");
#endif

	uint16_t x = a + 0x1b;
	uint16_t y = a + 0x1a;

	uint8_t* p = Data_234920d8;
	uint32_t dwData = (p[x] << 8) | p[y];

	uint16_t u = a + 0x15;
	uint16_t v = a + 0x14;

	dwData |= (p[u] << 26);
	dwData |= (p[v] << 16);

	return dwData;
}


/* 23415178 - complete */
void fatfs_handle_long_file_name(uint16_t offset)
{
#if 0
	console_send_string("fatfs_handle_long_file_name (todo.c): TODO\r\n");
#endif

	uint16_t r0;
	uint8_t r5 = get_byte(offset);

	if (r5 == 0xe5)
	{
		return;
	}

	offset += 1;

	if ((r5 & 0x040/*LAST_LONG_ENTRY*/) != 0)
	{
		memset(&fatfs_lfn.bytes[0], 0, 0x100);

		fatfs_lfn.valid = 1;
		fatfs_lfn.entries = r5;
	}
	//loc_234151bc
	fatfs_lfn.offset = ((r5 & 0x0f) - 1) * 13;
	if (fatfs_lfn.offset >= 0xf3)
	{
		return;
	}

	//LDIR_Name1
	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 0], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 1], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 2], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 3], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 4], 1);

	offset += 5;

	//LDIR_Name2
	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 5], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 6], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 7], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 8], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 9], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 10], 1);

	offset += 4;

	//LDIR_Name3
	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 11], 1);

	offset += 2;

	r0 = get_word(offset);
	sub_23457bf0(r0, &fatfs_lfn.bytes[fatfs_lfn.offset + 12], 1);
}


/* 234153a8 - todo */
void fatfs_string_copy(char* r4, char* r5, int r7)
{
#if 0
	console_send_string("fatfs_string_copy (todo.c): TODO\r\n");
#endif

	int16_t r6 = 0;

	uint32_t r0 = (int16_t) strlen(r4);
	while (r0 != 0)
	{
		r0--;
		if (r4[r0] != ' ')
		{
			break;
		}
	}

	r0++;

	int16_t r2 = r0;
//	r0 = r2;
	while (r0 != 0)
	{
		r0--;
		if (r4[r0] == '.')
		{
			break;
		}
	}

	int16_t r1 = r0 + 1;
	if (r7 != 0)
	{
		for (uint32_t r0 = 0; r0 < (r1 - 1); r0++)
		{
			if (r4[r0] != ' ')
			{
				r6 = r0 + 1;
			}
		}
	}
	else
	{
		r6 = r1 - 1;
	}

	uint32_t i;
	for (i = 0; i < r6; i++)
	{
		r5[i] = r4[i];
	}

	for (uint32_t k = r1 - 1; k < r2; k++, i++)
	{
		r5[i] = r4[k];
	}

	r5[i] = 0;
}


/* 23415488 - todo */
void sub_23415488(Struct_235af5d0* a)
{
#if 1
	console_send_string("sub_23415488 (todo.c): TODO\r\n");
#endif

	uint8_t sp4[24]; //size???

	int sl;
	int sb = 0;
	int r6 = 0; 

	fatfs_lfn.valid = 0;

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
			int r0 = fatfs_is_lfn(r5);
			if (r0 != 0)
			{
				fatfs_handle_long_file_name(r5);
				//->loc_234155fc
				//continue;
			}
			else
			{
				//loc_234154ec
				r0 = sub_23415074(r5);
				if (r0 != 0)
				{
					fatfs_lfn.valid = 0;
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
						r0 = fatfs_is_directory(r5);
						if (r0 == 0)
						{
							//0x23415570
							r0 = fatfs_is_archive(r5);
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
					
					r0 = fatfs_is_directory(r5);
					if (r0 == 0)
					{
						//0x234155ac
						r0 = fatfs_is_archive(r5);
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
					if (fatfs_lfn.valid != 0)
					{
						fatfs_lfn.valid = 0;
					}
					//loc_234155fc
				}
			}
		} //for (uint8_t r7 = 0; r7 <= 15; r5 += 32, r7++)
	} 
	while (sl != -1);
	//loc_2341561c
}


/* 23415624 - todo */
int sub_23415624(Struct_235af5d0* a, int b, char* c)
{
#if 0
	console_send_string("sub_23415624 (todo.c): TODO\r\n");
#endif

	int r5 = 0;
	int r8 = 0;
	int fp = 0;

	while (1)
	{
		//loc_23415638
		int sb = sub_234148c4(a, b, r8++, 0);
		if (sb == -1)
		{
			//->loc_23415738
			break;
		}
		//0x23415658
		for (uint8_t r6 = 0; r6 < 15; r6++)
		{
			//loc_2341565c
			int r7 = r6 << 5;

			if (0 != fatfs_is_lfn(r7))
			{
				fatfs_handle_long_file_name(r7);
				//->loc_23415720
			}
			//loc_2341567c
			else if (0 != sub_23415074(r7))
			{
				fatfs_lfn.valid = 0; //fp;
				//->loc_23415720
			}
			else if (0 != sub_234150c8(r7))
			{
				//0x234156a4
				if (fatfs_lfn.valid != 0)
				{
					if (0 != (fatfs_string_compare(&fatfs_lfn.bytes[0], c)))
					{
						//0x234156cc
						//->loc_23415710
						return get_first_cluster(r7);
					}

					fatfs_lfn.valid = 0; //fp;
					//->loc_23415720
				}
				else
				{
					//loc_234156d0
					for (uint8_t r4 = 0; r4 < 11; r4++)
					{
						//loc_234156d4
						/*sl*/Data_235ae9bc[r5] = get_byte(r7 + r4);

						r5++;
					}
					//0x234156f8
					/*sl*/Data_235ae9bc[r5] = 0; //fp

					if (0 != fatfs_string_compare(&Data_235ae9bc[0], c))
					{
						//loc_23415710
						return get_first_cluster(r7);
					}
					//loc_2341571c
					r5 = 0;
				}
			}
			//loc_23415720
		} //for (uint8_t r6 = 0; r6 < 15; r6++)
		//0x23415730
		if (sb == -1)
		{
			break;
		}
	}
	//loc_23415738
	return 0;
}


/* 23415740 - todo */
int sub_23415740(Struct_235af174* r4)
{
#if 0
	console_send_string("sub_23415740 (todo.c): TODO\r\n");
#endif

	if (r4 == 0)
	{
		return 1;
	}

	uint32_t r2 = r4->Data_235af2bc >> 4;
	uint32_t r6 = (r4->Data_235af2bc & 0x0f) << 5;

	int r0 = sub_234148c4(r4->Data_235af2c8, r4->Data_235af2b8, r2, 0);
	if (r0 == -1)
	{
		return 6;
	}

	//r5 = &fatfs_lfn;
	if ((get_byte(r6) == 0) || (get_byte(r6) == 0xe5))
	{
		//loc_234157a4
		r4->bData_235af1a9 = 0xe5;
		r4->bData_0x140 = 0; //r7
		fatfs_lfn.valid = 0;

		//->loc_23415864
	}
	//loc_234157b8
	else if (0 != fatfs_is_lfn(r6))
	{
		//0x234157c8
		fatfs_handle_long_file_name(r6);
		r4->bData_235af1a9 = get_byte(r6);
		r4->bData_0x140 = get_byte(r6 + 11);
		//->loc_23415864
	}
	//loc_234157f0
	else if (sub_234150c8(r6) == 0)
	{
		r4->bData_235af1a9 = 1;
		//->loc_23415864
	}
	else
	{
		if (fatfs_lfn.valid != 0)
		{
			//0x23415814
			r4->bData_235af1a9 = 0;

			strncpy(&r4->bData_235af1a9, &fatfs_lfn.bytes[0], 0x100);

			r4->bData_0x34 = fatfs_lfn.entries;
			fatfs_lfn.valid = 0;
		}
		//loc_23415834
		uint8_t i;
		for (i = 0; i < 11; i++)
		{
			//loc_23415838
			r4->shortFileName[i] = get_byte(i + r6);
		}
		//0x2341585c
		r4->shortFileName[i] = 0;
	}
	//loc_23415864
	r4->bData_1 = (fatfs_is_directory(r6) != 0);
	r4->bAttr = get_byte(r6 + 11);
	r4->Data_8 = get_first_cluster(r6);
	r4->Data_4 = get_filesize(r6);
	r4->Data_0xc = 0;
	r4->Data_0x10 = 0;
	r4->Data_0x20 = 0;
	r4->Data_0x24 = 0;
	
	return 0;
}


/* 234158b8 - todo */
int sub_234158b8(Struct_235af5d0* a, int b, char* c, Struct_235af620** d)
{
#if 0
	console_send_string("sub_234158b8 (todo.c): TODO\r\n");
#endif

	int r7;
	int sb = 0;
//	int sl = 0;
	//fp, =0x235af4cc
	Struct_235af620* r4 = *d;
	uint8_t r6;

#if 1
	{
		extern char debug_string[];
		sprintf(debug_string, "sub_234158b8: b=%d, c='%s'\r\n", 
			b, c);
		console_send_string(debug_string);
	}
#endif

	while (1)
	{
		//loc_234158cc
		int r8 = sub_234148c4(a, b, sb++, 0);
#if 1
		{
			extern char debug_string[];
			sprintf(debug_string, "sub_234158b8: r8=%d, sb=%d\r\n", 
				r8, sb);
			console_send_string(debug_string);
		}
#endif
		if (r8 == -1)
		{
			//->loc_23415a2c
			return 1;
		}

		for (r6 = 0; r6 < 16; r6++, r4->Data_0x148++)
		{
			//loc_234158f0
			r7 = r6 << 5;

			if (0 != fatfs_is_lfn(r7))
			{
				//0x23415904
				fatfs_handle_long_file_name(r7);
				//->loc_23415a08
			}
			//loc_23415910
			else if (0 != sub_23415074(r7))
			{
				fatfs_lfn.valid = 0; //sl
				//->loc_23415a08
			}
			//0x23415924
			else if (0 != sub_234150c8(r7))
			{
				//0x23415934
				if (fatfs_lfn.valid != 0)
				{
					//0x23415940
					memcpy(&r4->arData_0x35[0], &fatfs_lfn.bytes[0], 0x100);

					r4->bData_0x34 = fatfs_lfn.entries;
					fatfs_lfn.valid = 0; //sl
					//->loc_23415990
				}
				else
				{
					//loc_23415960
					uint8_t r5;
					for (r5 = 0; r5 < 11; r5++)
					{
						//loc_23415964
						r4->arData_0x35[r5] = get_byte(r5 + r7);
					}
					r4->arData_0x35[r5] = 0;
				}
				//loc_23415990
#if 1
				{
					extern char debug_string[];
					sprintf(debug_string, "sub_234158b8: r4->arData_0x35='%s'\r\n", 
						&r4->arData_0x35[0]);
					console_send_string(debug_string);
				}
#endif
				if (0 != fatfs_string_compare(&r4->arData_0x35[0], c))
				{
					//0x234159a4
					if (0 != fatfs_is_archive(r7))
					{
						//0x234159b4
						r4->bData_0 = get_byte(r7 + 11);
						r4->Data_8 = get_first_cluster(r7);
						r4->dwSize = get_filesize(r7);
						r4->Data_0xc = 0;
						r4->Data_0x10 = 0;
						r4->Data_0x20 = 0;
						r4->Data_0x24 = 0;
						r4->Data_0x30 = 0;
						r4->Data_0x154 = a;
						r4->Data_0x144 = r8;

#if 1
						{
							extern char debug_string[];
							sprintf(debug_string, "sub_234158b8: r4->Data_8=%d, r4->dwSize=%d\r\n", 
								r4->Data_8, r4->dwSize, r4->Data_0x154);
							console_send_string(debug_string);
						}
#endif

						return 0;
					}
					else
					{
						//loc_23415a2c
						return 1;
					}
				}
				//loc_23415a08
			}
			//loc_23415a08
		} //for (uint8_t r6 = 0; r6 < 16; r6++)
		//0x23415a24
		if (r8 == -1)
		{
			//loc_23415a2c
			return 1;
			//break;
		}
		//->loc_234158cc
	}
//	return 0;
}


/* 23415c0c - todo */
int sub_23415c0c(Struct_235af5d0* r8, int r6, char* fp, Struct_235af620** d, uint8_t e)
{
#if 0
	console_send_string("sub_23415c0c (todo.c): TODO\r\n");
#endif

	Struct_235af620* r4 = *d;

	Struct_235af620* sp_0x30;
	char sp_0x24[12] = {0};
	int sp4[8] = {0};
	
	memset(&Data_235aeabc, 0, sizeof(Data_235aeabc));
	memset(&Data_235aec14, 0, sizeof(Data_235aec14));

	uint8_t r7 = strlen(fp);

	if (fp[0] != '.')
	{
		//0x23415c88
		sprintf(&sp_0x24[0], "%0x", crc32(fp, strlen(fp)));

		uint8_t r5;

		//TODO!!!
		r5 = r7 / 13;
		if ((r7 % 13) != 0)
		{
			r5++;
		}
		r7 = r5 + 1;

		if (r7 > 8)
		{
			return 5;
		}
		//0x23415ce8
		Data_235aec14.Data_0x144 = r6;
		Data_235aec14.Data_0x148 = 0; //sb
		Data_235aec14.Data_0x154 = r8;
		r5 = 0;
		//->loc_23415da8
		while (r5 != r7)
		{
			//loc_23415cfc
			Data_235aec14.arData_0x35[0] = 0; //sb

			if (0 != sub_23415740(&Data_235aec14))
			{
				//0x23415d10
				sp_0x30 = &Data_235aeabc;

				if (r6 == 0)
				{
					r6 = 2;
				}

				Data_235aeabc.Data_0x154 = r8;
				Data_235aeabc.Data_0x30 = 0; //sb
				Data_235aeabc.Data_8 = r6;

				sub_23414b5c(&sp_0x30, 1);

				sub_23414c70(r8, sp_0x30->Data_0x30);
				//->loc_23415da8
			}
			else
			{
				//loc_23415d4c
				int r1 = Data_235aec14.Data_0x140;
				int r0 = 0xf;
				r0 = r0 & ~r1;
				if (r0 == 0)
				{
					Data_235aec14.Data_0x148 += (Data_235aec14.arData_0x35[0] & 0x0f);
					//->loc_23415da4
				}
				//0x23415d6c
				else 
				{
					if (Data_235aec14.arData_0x35[0] == 0xe5)
					{
						//0x23415d7c
						uint8_t r0 = r5 + 1;
						sp4[r5] = Data_235aec14.Data_0x148;
						r5 = r0;
						if (r5 == r7)
						{
							//->loc_23415db0
							break;
						}
						//loc_23415d9c
					}
					else
					{
						r5 = 0;
					}
					//->loc_23415d9c
					Data_235aec14.Data_0x148++;
				}
			}
			//loc_23415da8
		} //while (r5 != r7)
		//loc_23415db0
		r7 = r5 - 1;
		//->loc_23415e08
		for (r5 = 0; r5 < r7; r5++)
		{
			//loc_23415dc0
			Data_235aec14.Data_0x148 = sp4[r5];

			if (r5 == 0)
			{
				//0x23415dd8
				int r0 = sub_23416b54(&sp_0x24[0]);
				//->loc_23415df0
				sub_23415a34(&Data_235aec14, fp, r7 | 0x40, r0);
			}
			else
			{
				//loc_23415de4
				int r0 = sub_23416b54(&sp_0x24[0]);
				//->loc_23415df0
				sub_23415a34(&Data_235aec14, fp, (r7 - r5) & 0xff, r0);
			}
		}
		//0x23415e10
		Data_235aec14.Data_0x154 = r8;
		Data_235aec14.Data_0x148 = sp4[r7];
		Data_235aec14.Data_0x144 = r6;

		*r4 = Data_235aec14;

		r4->wData_2 = 0x600;
		r4->dwSize = 0; //sb
		r4->bData_0 = e;
		r4->Data_8 = 0; //sb
		r4->Data_0x30 = 0; //sb

		for (uint8_t r0 = 0; r0 < 11; r0++)
		{
			//loc_23415e58
			r4->arData_0x35[r0] = sp_0x24[r0];
		}
		//0x23415e74
		sub_234149a8(r4);
		//->loc_23415f24
	} //if (fp[0] != '.')
	else
	{
		Data_235aec14.Data_0x144 = r6;
		Data_235aec14.Data_0x148 = 0; //sb
		Data_235aec14.Data_0x154 = r8;
		//->loc_23415f14
		while (0 == sub_23415740(&Data_235aec14))
		{
			//loc_23415e80
			if (Data_235aec14.arData_0x35[0] == 0xe5)
			{
				//0x23415e8c
				*r4 = Data_235aec14;

				r4->wData_2 = 0x600;
				r4->dwSize = 0; //sb
				r4->bData_0 = e;
				r4->Data_8 = 0; //sb
				r4->Data_0x30 = 0; //sb

				memset(&r4->arData_0x35[0], ' ', 0x100);

				uint8_t r1 = strlen(fp);

				for (uint8_t r0 = 0; r0 < r1; r0++)
				{
					//loc_23415ed8
					r4->arData_0x35[r0] = fp[r0];
				}
				//0x23415ef4
				sub_234149a8(r4);

				return 0;
			}
			//loc_23415f08
			Data_235aec14.Data_0x148++;
			//loc_23415f14
		} ///while (0 == sub_23415740(&Data_235aec14))
		//loc_23415f24
	}
	//loc_23415f24
	return 1;
}


/* 23415f44 /  / 2341d958 - complete */
int fatfs_volume_add_usb_device(USB_MSD_Interface* r4)
{
#if 0
	console_send_string("fatfs_volume_add_usb_device (todo.c): TODO\r\n");
#endif

	memset(Data_235af5d0, 0, sizeof(Data_235af5d0));

	Data_235af5d0[0].read = r4->read;
	Data_235af5d0[0].write = r4->write;
	Data_235af5d0[0].pDev = r4->pDevice; 
	Data_235af5d0[0].Data_0x48 = r4->Data_20;

	Data_234920d8 = &Data_235af2cc;

	if (Data_234920d4 == 0)
	{
		Data_234920d4 = OSSemCreate(1);
	}

	memset(&Data_235af620[0], 0, sizeof(Data_235af620));

    return 0;
}


/* 23415fb4 /  / 2341d9c8 - complete */
int fatfs_init(int a)
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

	Data_235af5d0[r4].pDev = 0;

	OSSemPost(Data_234920d4);

	return 0;
}


/* 234160e8 - todo */
int fatfs_open_file(void** a, char* r5, int c, int r4_)
{
#if 0
	console_send_string("fatfs_open_file (todo.c): TODO\r\n");
#endif

	Struct_235af620** r8 = a;
	uint8_t sp8; // = 0;
	int sp4 = 0;
	int r7 = 2;
	int sb = 4;
	uint8_t sl;

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "fatfs_open_file: r5='%s', c=0x%x, r4_=%d\r\n", 
			r5, c, r4_);
        console_send_string(debug_string);
    }
#endif

	if ((r5 == 0) || (strlen(r5) > 100))
	{
		return 1;
	}

	if (r5[0] == 0x2f)
	{
		r5++;
	}

	fatfs_wait_semaphore();

	if (r4_ != 0)
	{
		r7 = r4_;
	}

	char* r0 = &Data_235afd0c[0];
	char* r1 = &Data_235afd70[0];
	char* r4 = r5;
	while (1)
	{
		//loc_23416150
		if (*r4 == 0)
		{
			//->loc_23416170
			break;
		}
		r4++;
	}
	//loc_23416170
	while (r4 != r5)
	{
		//loc_23416164
		r4--;
		if (*r4 == 0x2f)
		{
			//->loc_23416188
			break;
		}
	}
	//0x23416178
	if (*r4 == 0x2f)
	{
		//loc_23416184
		r4++;
	}
	//loc_23416188
	char* r3 = r4;
	while (1)
	{
		//loc_2341618c
		char r2 = *r4++;
		char* ip = r1++;
		*ip = r2;
		if (r2 == 0)
		{
			break;
		}
	}
	//0x234161a4
	r1 = r5;
	while (r1 < r3)
	{
		//loc_234161a8
		char ip = *r1++;
		char* r2 = r0 + 1;
		*r0 = ip;
		r0 = r2;
	}
	//0x234161c0
	if ((r3 > (r5 + 1)) && (r0[-1] == 0x2f))
	{
		r0--;
	}
	//loc_234161d8
	*r0 = 0;

	r1 = &Data_235afd0c[0];
	uint8_t r0_; // = 0;
	//->loc_23416200
	for (r0_ = 0; *r1 != 0; r0_++)
	{
		//loc_234161ec
		while (*r1++ != 0x2f) {}

		r0_++;
	}
	//0x2341620c

#if 1
    {
        extern char debug_string[];
        sprintf(debug_string, "fatfs_open_file: Data_235afd0c='%s', r0_=%d\r\n", 
			&Data_235afd0c[0], r0_);
        console_send_string(debug_string);
    }
#endif

	sp8 = r0_;
	int fp = c & 0x300;
	//->loc_234162e4
	for (sl = 0; sl < sp8; sl++)
	{
		//loc_23416220
		char* r5 = &Data_235afd0c[0];
		uint8_t r6 = 0;
		int r4 = 0;

		uint16_t r2 = strlen(r5);
		//r3 = 235AFCD8
		//->loc_23416274
		for (uint8_t r0 = 0; r0 < r2; r0++)
		{
			//loc_23416244
			char r1 = *r5;
			if (r1 == 0x2f)
			{
				r6++;
			}

			if (r6 == sl)
			{
				//0x2341625c
				if (r1 != 0x2f)
				{
					Data_235afcd8[r4] = r1;
					r4++;
				}
			}
			//loc_23416268
			r5++;
		} //for (uint8_t r0 = 0; r0 < r2; r0++, r5++)
		//0x2341627c
		Data_235afcd8[r4] = 0;

		int r5_ = r7;

		Struct_235af5d0* r4_ = &Data_235af5d0[sp4];

		r7 = sub_23415624(r4_, r7, &Data_235afcd8[0]);

		if (r7 == 0)
		{
			if (fp == 0x200)
			{
				//0x234162b8
				sub_23416bc8(r4_, r5_, &Data_235afcd8[0]);

				r7 = sub_23415624(r4_, r5_, &Data_235afcd8[0]);
			}
			else
			{
				//->loc_23416300
				int r4 = 5;
				OSSemPost(Data_234920d4);
				//->loc_23416124
				return r4;
			}
		}
		//loc_234162dc
	} //for (uint8_t sl = 0; sl < sp8; sl++)
	//0x234162f0
	//r6, =0x235af620
	//r4 = 0;
	//r5, #0x2b
	//->loc_23416318
	for (uint8_t r4 = 0; r4 < 5; r4++)
	{
		//loc_23416318
		if (Data_235af620[r4].wData_2 == 0)
		{
			//0x2341632c
#if 1
			{
				extern char debug_string[];
				sprintf(debug_string, "fatfs_open_file: r4=%d, sp4=%d\r\n", 
					r4, sp4);
				console_send_string(debug_string);
			}
#endif

			sb = 0;
			*r8 = &Data_235af620[r4];
			r4 = 0;

			(*r8)->wData_2 = 0;

			if (0 != sub_234158b8(&Data_235af5d0[sp4], r7, &Data_235afd70[0], r8))
			{
				//0x23416370
				if (fp == 0x100)
				{
					sb = 5;
				}
				//0x2341637c
				else if (fp == 0x200)
				{
					//0x23416384
					int r3 = 0x20;
					if ((/*sp_0x14*/c & 3) == 0)
					{
						r3 = 0x21;
					}
					sub_23415c0c(&Data_235af5d0[sp4], r7, &Data_235afd70[0], r8, r3);

					(*r8)->wData_2 |= 0x100;
				}
				//->loc_2341644c
//				break;
			}
			//loc_234163c0
			else if (fp == 0x100)
			{
				//0x234163c8
				(*r8)->wData_2 |= 0x100;
				(*r8)->Data_0x18 = r4;
				(*r8)->Data_0x1c = r4;
				//->loc_2341644c
//				break;
			}
			//loc_234163ec
			else if (fp == 0x200)
			{
				//0x234163f4
				uint8_t* r1 = &((*r8)->bData_0);
				sb = 4;
				int i = 0x158;
				while (i != -1)
				{
					//loc_23416400
					i--;
					if (i != -1)
					{
						r1[0] = r4;
					}
				}
				//0x23416410
				//->loc_2341644c
			}
			//loc_2341644c
			break;
		}
		//loc_23416414
		if (Data_235af620[r4].Data_0x144 == r7)
		{
			//0x23416420
			if (0 == memcmp(&Data_235afd70[0], &Data_235af620[r4].arData_0x35[0], 11))
			{
				sb = 4;
				//->loc_2341644c
				break;
			}
		}
		//loc_2341643c
	} //for (uint8_t r4 = 0; r4 < 5; r4++)
	//loc_2341644c
	OSSemPost(Data_234920d4);
	return sb;
}


/* 23416460 /  / 2341de74 - todo */
int fatfs_read_file(void** a, uint8_t* sb, int32_t r5, int* r8)
{
#if 0
	console_send_string("fatfs_read_file (todo.c): TODO\r\n");
#endif

	Struct_235af620* r4 = *a;

	uint32_t sp4 = r5;
	int sp;
	Struct_235af5d0* r7 = r4->Data_0x154;

	if (r4 == 0)
	{
		*r8 = 3;

		return 0;
	}
	//0x23416490
	fatfs_wait_semaphore();

	*r8 = 0; //r6

	uint32_t r3 = (r4->Data_0x154->wBytsPerSec * r4->Data_0xc + r4->Data_0x10);
	uint32_t lr = r3 + r5;

	if (lr > r4->dwSize)
	{
		r5 = r4->dwSize - r3;
		sp4 = r5;
	}

	if (r4->Data_0x10 != 0)
	{
		//0x234164cc
		sub_234148c4(r4->Data_0x154, r4->Data_8, r4->Data_0xc, &r4->Data_0x18);
		//->loc_234164f4
		while ((r4->Data_0x10 < r4->Data_0x154->wBytsPerSec) || (r5 == 0))
		{
			//loc_234164dc
			*sb++ = get_byte(r4->Data_0x10++);
			r5--;
		}
		//0x23416510
		if (r4->Data_0x10 == r4->Data_0x154->wBytsPerSec)
		{
			//0x23416524
			r4->Data_0x10 = 0; //r6;
			r4->Data_0xc++;
			//->loc_23416658
		}
		else
		{
			//loc_23416660
			OSSemPost(Data_234920d4);

			return sp4;
		}
	}
	//loc_23416658
	while (r5 > 0)
	{
		//loc_23416538
		uint32_t r6 = r7->wSectorsPerCluster;
		uint32_t fp = r4->Data_0xc;
		int r8 = r4->Data_8;
		uint32_t sl = fp / r6;
		uint32_t r0 = r6 * sl;
		r6 = 0;
		r0 = fp -r0;
		sp = r0;

		if ((r4->Data_0x18 != 0) &&
			//0x23416570
			(r4->Data_0x18 <= sl))
		{
			r8 = r4->Data_0x1c;
			r6 = r4->Data_0x18 - 1;
		}
		//->loc_2341659c
		while (r6 < sl)
		{
			//loc_23416580
			r4->Data_0x1c = r8;
			r4->Data_0x18 = sl;

			r8 = sub_234147d8(r7, r8);

			r6++;
		}
		//0x234165a4
		if (r8 == -1)
		{
			sp4 = 0;
			//->loc_23416660
			break;
		}
		//0x234165b4
		r6 = r5 / r7->wBytsPerSec;

		if (r7->wBytsPerSec > r5)
		{
			r4->Data_0x10 = r5;
			r6++;
		}

		sl = r7->wSectorsPerCluster;
		fp = r4->Data_0xc;
		
		r0 = fp / sl;
		r0 = r0 + 1;
		uint32_t r1 = fp + r6;
		r0 = sl * r0;
		int r2 = r8 - 2;

		if (r1 > r0)
		{
			r6 = r0 - fp;
		}

		r1 = r2 * sl + sp;
		Data_234920dc = r1 + r7->Data_0x24;

		(r7->read)(r7->pDev, Data_234920dc, sb, r6);

		if (r4->Data_0x10 == 0)
		{
			r4->Data_0xc += r6;
		}

		int r0_ = r7->wBytsPerSec;
		sb += r6 * r0_;

		if (r0_ >= r5)
		{
			//->loc_23416660
			break;
		}
		//0x23416650
		r0_ = r0_ * r6;
		r5 = r5 - r0_;
		//loc_23416658
	} //while (r5 > 0)
	//loc_23416660
	OSSemPost(Data_234920d4);

	return sp4;
}


/* 234168d0 /  / 2341e2e4 - complete */
void* fatfs_volume_get_usb_device(int a)
{
#if 0
	console_send_string("fatfs_volume_get_usb_device (todo.c): TODO\r\n");
#endif

	Struct_235af5d0* r4_ = &Data_235af5d0[a];

	fatfs_wait_semaphore();

	void* pDev = r4_->pDev;

	OSSemPost(Data_234920d4);

	return pDev;
}


/* 234168fc - todo */
int sub_234168fc(int a, Struct_234168fc* r4)
{
#if 0
	console_send_string("sub_234168fc (todo.c): TODO\r\n");
#endif
	
	Struct_235af5d0* r6 = &Data_235af5d0[a];

	fatfs_wait_semaphore();

	Data_235af174.Data_235af2c8 = r6;
	Data_235af174.Data_235af2bc = r4->Data_0;
	Data_235af174.Data_235af2b8 = r4->Data_4;
	Data_235af174.bData_235af1a9 = 0;
	Data_235af174.shortFileName[0] = 0;

	r4->arFileName[0] = 0;

	int r6_ = sub_23415740(&Data_235af174);

	if ((Data_235af174.shortFileName[0] != 0) &&
		(Data_235af174.shortFileName[0] != 0xe5))
	{
		//0x23416958
		if (Data_235af174.bData_235af1a9 != 0)
		{
			strncpy(&r4->arFileName[0], &Data_235af174.bData_235af1a9, 0x100);
		}
		else
		{
			strncpy(&r4->arFileName[0], &Data_235af174.shortFileName[0], 12);
		}

		r4->bData_0x10 = Data_235af174.bData_1;
		r4->Data_4 = (Data_235af174.Data_8 != 0)? Data_235af174.Data_8: 2;
		r4->Data_8 = Data_235af174.Data_4;
	}
	//loc_2341699c
	OSSemPost(Data_234920d4);

	return r6_;
}


/* 234169c0 /  / 2341e3d4 - complete */
int fatfs_get_file_size(void* a)
{
#if 0
	console_send_string("fatfs_get_file_size (todo.c): TODO\r\n");
#endif

	Struct_235af620* r0 = a;

	return r0->dwSize;
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

	uint16_t w = *(addr + offset + 1) << 8;
	w += (*(addr + offset) << 0);

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
int fatfs_is_lfn(uint32_t offset)
{
#if 0
	console_send_string("fatfs_is_lfn (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;
	uint8_t r2 = 0x0f;

	offset += 11;

	return ((r2 & ~(*(addr + offset))) == 0)? 1: 0;
}


/* 23416b08 - todo */
int fatfs_is_archive(uint32_t a)
{
#if 0
	console_send_string("fatfs_is_archive (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;

	uint16_t offset = a + 11;

	if (0x20 & *(addr + offset))
	{
		return 1;
	}

	return 0;
}


/* 23416b28 - complete */
int fatfs_is_directory(uint32_t offset)
{
#if 0
	console_send_string("fatfs_is_directory (todo.c): TODO\r\n");
#endif

	uint8_t* addr = (uint8_t*)Data_234920d8;

	uint16_t attr_offset = offset + 11;

	if (0x10 & *(addr + attr_offset))
	{
		return 1;
	}

	return 0;
}


/* 23416b48 - complete */
int get_filesize(int a)
{
#if 0
	console_send_string("get_filesize (todo.c): TODO\r\n");
#endif

	return get_dword(a + 0x1c);
}


/* 23416b8c - complete */
int fatfs_string_compare(char* a, char* b)
{
#if 0
	console_send_string("fatfs_string_compare (todo.c): TODO\r\n");
#endif

	fatfs_string_copy(a, &Data_235ae7bc[0], 0);
	fatfs_string_copy(b, &Data_235ae8bc[0], 0);

#if 0
	{
		extern char debug_string[];
		sprintf(debug_string, "fatfs_string_compare: Data_235ae7bc='%s', Data_235ae8bc='%s'\r\n", 
			&Data_235ae7bc[0], &Data_235ae8bc[0]);
		console_send_string(debug_string);
	}
#endif

	return strcmp(&Data_235ae7bc[0], &Data_235ae8bc[0]) == 0;
}


/* 23416bc8 - todo */
int sub_23416bc8(Struct_235af5d0* r6, int r5, char* r2)
{
#if 0
	console_send_string("sub_23416bc8 (todo.c): TODO\r\n");
#endif

	/*Struct_235aed6c*/Struct_235af620* sp4;

	Data_235aed6c.Data_0x154 = r6;
	Data_235aed6c.Data_0x144 = r5;
	Data_235aed6c.Data_0x148 = 0; //r7

	sp4 = &Data_235aed6c;

	sub_23415c0c(r6, r5, r2, &sp4, 0x10);

	Data_235aed6c.Data_8 = 0; 

	sub_23414b5c(&sp4, 1);

	int r4 = sp4->Data_8;

	sub_234146b4(r6, r4, -1);

	sub_23414c70(r6, r4);

	sub_23415c0c(r6, r4, ".", &sp4, 0x10);

	sp4->Data_8 = r4;

	sub_234149a8();

	sub_23415c0c(r6, r4, "..", &sp4, 0x10);

	sp4->Data_8 = r5;

	sub_234149a8();

	return 0;
}


