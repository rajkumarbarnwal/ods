#include<stdio.h>
void pattern(int n1, int n2)
{
    for(int i=1; i<=n2; i++)
    {
        for(int j=1; j<=n1; j++)
        {
            if(i==1||i==n2||j==1||j==n1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }   
        }
        printf("\n");
    }
}
int main()
{
    int n1,n2;
    printf("enter values:");
    scanf("%d%d",&n1,&n2);
    pattern(n1,n2);
}
