

typedef struct PAT_Program
{
	int program_number; //0
	int pmt_pid; //4
	struct PAT_Program* next; //8
	//12
} PAT_Program;


int pat_get_num_programs(uint8_t);
struct PAT_Program* pat_get_program(uint8_t, uint8_t);


