#include <stdio.h>

int mdc(int x, int y)
{
    if(y == 0)
        return x;
        
    return mdc(y, x % y);
}

int main()
{
    int x, y;
    scanf("%d %d", & x, & y);
    printf("\n%d",mdc(x,y));
}