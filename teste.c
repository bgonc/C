#include <stdio.h>

int main()

{
    int n;
    int r;
    int i;
    int a;

    printf("Calculo dos arranjos de N, R a R:\n");
    printf("Indique N: ");
    scanf("%d", &n);
    printf("Indique R: ");
    scanf("%d", &r);

    i=n-r+1;
    a=1;

    while(i<=n)
    {    
        a*=i;

        printf("i=%d; arranjos=%d\n", i, a);
        i++;

    }
    printf("Resultado=%d\n", a);


}