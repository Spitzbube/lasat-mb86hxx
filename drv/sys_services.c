

/* 2341a8fc - todo */
int sys_get_device_id(void)
{     
   volatile int* reg = (void*) 0xd5000000;
   int r1 = reg[0];
   int r0 = reg[3];
   
   if (r1 != -1)
   {
      if ((r0 & 0xFF) == 0xFF)
      {
         return 0x48363000; //H60
      }
      
      if ((r0 & 0xFF) == 0xFE)
      {
         return 0x48363042; //H60B
      }
   }
         
   return 0;
}
