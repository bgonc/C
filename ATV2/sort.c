#include <stdio.h>

unsigned int randaux()
{
    static long seed=1;
  return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}

int PrintInts(int v[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
        
}

int Sort(int v[], int n)
{
    int aux;

    for(int i = 0; i < n; i++)
        

}

int main()
{
    int v[1000],i, n;

    scanf("%d",&n);
    n++;

    for(i=0;i<1000;i++)
		v[i]=randaux()%n;

	PrintInts(v,10);

	Sort(v,1000);


    
}