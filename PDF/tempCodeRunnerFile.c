#include <stdio.h>

int main()

{
    int n;
    int r;
    int i=1;

        printf("Indique N: ");
        scanf("%d", &n);    
        printf("Indique R: ");
        scanf("%d", &r);

    while(r<=n)
        {
            i*=r;
        
            printf("i=%d; arranjos=%d\n", r, i);
        r++;

        }
    printf("Resultado: %d\n", i);

}