#include <stdio.h>

int main()

{
    int n;
    int i=1;
    int resto=1;
    int zero=0;

    printf("Funcao que verifica se um numero N e' primo\nIndique N:\n");
    scanf("%d", &n);

    
    /*if(n%n == 0 && n%1 == 0 && n%i == 0)*/

    while(i<=n)
    {   
        resto=n%i;
        i++;
o 
        if(resto == 0)
        {
            zero++;
            if(zero == 2)
                printf("%d\n %d ", resto, zero);
            
            else
                printf("%d\n %d", resto, zero);
        
        }

    }


}