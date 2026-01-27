#pragma once



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "../types.h"




/**
 * Compile-time macro for determining value type. 
 * 
 * @author Ilya Alexandrovich
 * 
 * @return return string representing required value type
 * 
 * @since 1.0.8
 */
#define TYPENAME(x) _Generic((x),                                                     \
            _Bool: "_Bool",                  unsigned char: "unsigned char",          \
             char: "char",                     signed char: "signed char",            \
        short int: "short int",         unsigned short int: "unsigned short int",     \
              int: "int",                     unsigned int: "unsigned int",           \
         long int: "long int",           unsigned long int: "unsigned long int",      \
    long long int: "long long int", unsigned long long int: "unsigned long long int", \
            float: "float",                         double: "double",                 \
      long double: "long double",                   char *: "pointer to char",        \
           void *: "pointer to void",                int *: "pointer to int",         \
          default: "other"                                                            \
)



// Windows-specific high-resolution time acquairing functions.
#if defined _WIN32 || defined _WIN64
#include <Windows.h>
#include <profileapi.h>



// Number of clocks in code.
#define NUMBER_OF_CLOCKS 1

// Before every perfomance clock call this macro should be used.
// This helps to determine required number of preallocation.
#define ADD_CLOCK() (++NUMBER_OF_CLOCKS)



/**
 * Structure containing all required data to perform perfomance check.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param counter  structure containing high-resolution time
 * @param clockname  name of the clock responding for current instance
 * 
 * @since 1.0.8
 */
typedef struct _PerfomanceClock
{
     LARGE_INTEGER counter;
     char* clockname; 
} PerfomanceClock;



// Buffer of PerfomanceClock structures initialized
// with zeroes before any actions is taken. 
static PerfomanceClock* perfclocks = NULL;



/**
 * Initialize buffer of PerfomanceClock structure instances. This
 * function should be called instead of any other relative.
 * 
 * @author Ilya Alexandrovich
 * 
 * @since 1.0.8
 */
void InitializeClock();



/**
 * StartClock function(event) should be closed by EndClock. 
 * If so you should get perfomance right metrics.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param perfclock  pointer to the PerfomanceClock structure
 * @param clockname  the name of the current clock used for better
 * readability
 * 
 * @since 1.0.8
 */
void StartClock(char* const clockname);



/**
 * End performance measurement event. This function will 
 * not end any other calls either it will not force program
 * to exit or clean ANY resources.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param clockname  name of the current clock
 * 
 * @since 1.0.8
 */
void EndClock(char* const clockname);



/**
 * Process all existed clocks and show overall perfomance
 * metrics.
 * 
 * @author Ilya Alexandrovich
 * 
 * @since 1.0.8
 */
void ProcessClock();



/**
 * This is the opposite function to InitializeClock. This freeing 
 * all objects required to perform benchmarking.
 * 
 * @author Ilya Alexandrovich
 * 
 * @since 1.0.8
 */
void DeleteClock();


// Linux-specific high-resolution time acquairing functions.
#else

#endif
