//-----------------------------------------------------------------------------
//
// Variable m is responsible for the number of
// pseudo-random numbers needed, and the variable n is responsible for the
// number of pages used in the LIRS algorithm. Function TESTING_THREAD 
will
// be used in our further work.
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *testing_thread(int m, long long n)
{
    FILE *file;
    file = fopen("input.txt", "w");
    long long *a = (long long *) calloc(m, sizeof(long long));
    srand(time(NULL));
    for (int i = 0; i < m; ++i) {
        a[i] = rand() % n;
    }
    for (int i = 0; i < m; ++i) {
        fprintf(file, "%lld ", a[i]);
    }
    free(a);
    return file;
}
