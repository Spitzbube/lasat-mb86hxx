
#include <stdint.h>
#include "ucos_ii.h"


/* 23425d94 - complete */
void sys_invalidate_data_cache( uint32_t startAddress, uint32_t bytes )
{
#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
    register uint32_t end_address = ( startAddress + bytes ) - 1;

    OS_ENTER_CRITICAL();

    startAddress = startAddress & ~0x3;
    end_address  = (end_address + 3) & ~0x3;

    #if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
        __asm { mcrr p15,0,end_address,startAddress,c6 }
    #endif

    #if defined(__arm__) && defined(__GNUC__) && !defined(__polyspace__)
        asm volatile( "mcrr p15,0,%0,%1,c6" : : "r"(end_address), "r"(startAddress) );
    #endif

    #if defined(_ARC) && !defined(__polyspace__)
        for( ; startAddress <= end_address; startAddress+=16 )
            _sr( startAddress, 0x4A );
        while( ( _lr( 0x48 ) & 0x100 ) == 0x100 )
            ;
    #endif

    OS_EXIT_CRITICAL();
}


/* 23425dc0 - complete */
void sys_flush_data_cache( uint32_t startAddress, uint32_t bytes )
{
    /*lint -save -e529 -e550 -e957 */

#if OS_CRITICAL_METHOD == 3u                     /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr = 0u;
#endif
    register uint32_t end_address = ( startAddress + bytes ) - 1;

    OS_ENTER_CRITICAL();

    startAddress = startAddress & ~0x3;
    end_address  = (end_address + 3)  & ~0x3;

    #if defined(__arm__) && !defined(__GNUC__) && !defined(__polyspace__)
        __asm { mcrr p15,0,end_address,startAddress,c12 }
    #endif

    #if defined(__arm__) && defined(__GNUC__) && !defined(__polyspace__)
        asm volatile( "mcrr p15,0,%0,%1,c12" : : "r"(end_address), "r"(startAddress) );
    #endif

    #if defined(_ARC) && !defined(__polyspace__)
        for( ; startAddress <= end_address; startAddress+=16 )
            _sr( startAddress, 0x4C );
        while( ( _lr( 0x48 ) & 0x100 ) == 0x100 )
            ;
    #endif

    OS_EXIT_CRITICAL();
}


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
