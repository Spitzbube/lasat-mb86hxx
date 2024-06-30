

typedef struct
{
	OS_EVENT* sema; //0
	int idx; //4
	int addr; //8
	int size; //12
	//16
} MemBlk_Handle;


typedef struct
{
	int addr; //0
	int size; //4
	int fill_8[2]; //8

} MemBlk_Params;


MemBlk_Handle* memblk_open(MemBlk_Params*);
int memblk_init(void*);
void* memblk_alloc(void*, uint32_t);
int memblk_free(void*, void*);



