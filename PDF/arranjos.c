#include <stdio.h>

int main()

{
    int n, r;
    int i;
    int produto=1;

        printf("Indique N: ");
        scanf("%d", &n);
        printf("Indique R: ");
        scanf("%d", &r);

        i=n-r+1;

    while(i<=n)
        {
            
            produto*=i;
        
            printf("i=%d; arranjos=%d\n", i, produto);
        i++;

        }
    printf("Resultado: %d\n", i);

}