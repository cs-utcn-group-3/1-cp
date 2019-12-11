/*3.2;lab12*/
#include <stdio.h>
#include <stdlib.h>

int h(int n, int x)
{
    if(n==0) return 1;
    else
        if (n==1) return (2*x);
            else return (2*n*h(n-1,x)-2*(n-1)*h(n-2,x));
}



int main()
{
    int n,x;
    printf("n,x=");
    scanf("%d,%d",&n,&x);
    printf("Hermite value: %d",h(n,x));
    return 0;
}
