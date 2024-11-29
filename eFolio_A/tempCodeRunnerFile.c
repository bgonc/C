#include <stdio.h>

int main()
{
    int k;

    printf("Indique K: ");
    scanf("%d", &k);

    if(k >= 2 && k <= 100)
    {

        printf("Sequencia: %d %d\n", k / 2, k / 2);
    }
    else
        printf("K tem de ser entre 2 e 100.\n");
}