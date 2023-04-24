//-----------------------------------------------------------------------------
//
// Early version of the test generator for LIRS
//
//-----------------------------------------------------------------------------
//
// Explanation: the variable m is responsible for the number of pseudo-random 
// numbers needed, and the variable n is responsible for the number of pages 
// used in the LIRS algorithm. Function TESTING_THREAD will be used in our 
// further work.
// 
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *testing_thread(int m, int n)
{
    int *a;
    a = (int *) calloc(m, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < m; ++i)
    {
        a[i] = rand() % n;
    }
    return a;
}
