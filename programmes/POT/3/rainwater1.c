#include<stdio.h>
int RainWater(int A[],int n)
{
	int maxl,maxr,i,sum=0;
	int B1[n],B2[n];
	maxl=A[0];
	maxr=A[n-1];
	for(i=0;i<n;i++)
	{
		B1[i]=maxl;
		printf("%d ",B1[i]);
		if(A[i]>maxl)
			maxl=A[i];
	}
	printf("\n");
	for(i=n-1;i>=0;i--)
	{
		B2[i]=maxr;
		printf("%d ",B2[i]);
		if(A[i]>maxr)
			maxr=A[i];
	}
	for(i=1;i<n-1;i++)
	{
		if(B1[i]<=B2[i] && B1[i]>A[i])
			sum=sum+(B1[i]-A[i]);
		else
			if(B2[i]<=B1[i] && B2[i]>A[i])
				sum=sum+(B2[i]-A[i]);
	}
	return sum;
}
int main()
{
	int n,i,s;
	printf("enter no of buildings : ");
	scanf("%d",&n);
	int A[n];
	printf("Enter height of buildings : ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	s=RainWater(A,n);
	printf("\nTotal water trapped: %d ",s);
}
