//-----------------------------------------------------------------------------
//
// Variable m is responsible for the number of
// pseudo-random numbers needed, and the variable n is responsible 
// for the number of pages used in the LIRS algorithm. Function 
// TESTING_THREAD will be used in our further work.
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *testing_thread(int m, long long n)
{
    FILE *file;
    file = fopen("input.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        fprintf(file, "%lld ", rand() % n);
    }
    return file;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  FILE *file = testing_thread(m, n);
  fclose(file);
}
