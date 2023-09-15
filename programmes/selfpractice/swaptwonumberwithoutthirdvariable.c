#include <stdio.h>
int main()
{
    int x,y;
    printf("enter 1st number");
    scanf("%d",&x);
    printf("enter 2nd number");
    scanf("%d",&y);
    x=x+y;
    y=x-y;
    x=x-y;
    printf("after swaping X: %d \n Y: %d",x,y);

}