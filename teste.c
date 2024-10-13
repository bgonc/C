#include <stdio.h>

int main()
{

    int h;
    int m;
    int s;
    int hms;

    printf("Calculo do numero de segundos desde o inicio do dia.\n");
    printf("hora\n");
    scanf("%d", &h);
    printf("minuto\n");
    scanf("%d", &m);
    printf("segundo\n");
    scanf("%d", &s);

    hms=(((h*60)*60)+(m*60)+s);

    printf("Total: %d", hms);
}