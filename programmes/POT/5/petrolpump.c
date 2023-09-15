#include<stdio.h>
struct pump
{
	int capacity;
	int distance;
};
int travel(struct pump p[],int n)
{
	int start=0,end=1;
	int cp=p[start].capacity-p[start].distance;
	while(end!=start || cp<=0)
	{
		while(cp<0 && start!=end)
		{
			cp-=p[start].capacity-p[start].distance;
			start=(start+1)%n;
			if(start == 0)
			   return -1;
		}
		cp+=p[end].capacity-p[end].distance;
		end=(end+1)%n;
	}
	return start;
}
int main()
{
	struct pump p[]={{6,4},{3,6},{7,3}};
	int r;
	r=travel(p,3);
	if(r==-1)
	   printf("Not Possible");
	else
	   printf("Starting point %d",r);
	return 0;
}
