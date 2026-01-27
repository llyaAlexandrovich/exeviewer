#include "benchmark.h"








#if defined _WIN32 || defined _WIN64


void InitializeClock()
{
    perfclocks = (PerfomanceClock*)malloc(sizeof(PerfomanceClock) * NUMBER_OF_CLOCKS);

    if(perfclocks == NULL)
    {
        // Doing this is permit since this function being called first.
        exit(1);
    }
}



//void StartClock(char* const clockname)
//{
//    short counter = 0;
//
//    // Search for free PerfomanceClock instance through
//    // perfclocks buffer.
//    for(; &perfclocks[counter] != NULL; ++counter);
//
//    
//}

#else 



#endif
