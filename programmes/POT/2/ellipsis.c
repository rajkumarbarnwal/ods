#include<stdio.h>
int Add(int n,...)
{
	int *p=&n;
	int sum=0,i;
	for(i=1;i<=n;i++)
	    printf("%d ",*(p+i));
	   //sum=sum+*(p+i);
	return sum;
}
int main()
{
printf("\n%d",Add(2,3,5));
printf("\n%d",Add(3,6,7,8));
printf("\n%d",Add(4,8,7,9,2));	
} 





