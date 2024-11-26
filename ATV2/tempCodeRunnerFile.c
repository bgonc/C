#include <stdio.h>

unsigned int randaux()
{
static long seed=1;
  return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}


void PrintInts(int v[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
}


int main()
{