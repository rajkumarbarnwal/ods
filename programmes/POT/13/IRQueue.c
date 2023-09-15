#include<stdio.h>
#define size 5
typedef struct queue
{
	int q[size];
	int f,r;
}irqueue;

void del(irqueue *p,char side)
{
	if(p->f==-1)
		printf("Queue is empty.");
	else
	{
		if(p->f==p->r)//single element in queue
			p->f=p->r=-1;
		else if(side=='f' || side == 'F')
			++p->f;
		else if(side=='r' || side == 'R')
			--p->r;
		else
			printf("Invalid side is given");
		
	}
	
}
void insert(irqueue *p,int item)
{
	if(p->r==size-1)
		printf("Q is full");
	else
	{
		p->q[++p->r]=item;
		if(p->f==-1)
			p->f++;	
	}
}
void print(irqueue *p)
{
	int i;
	if(p->f==-1)
		printf("Queue is empty.");
	else
		for(i=p->f;i<=p->r;i++)
			printf("%d ",(*p).q[i]);
}
void main()
{
	irqueue que;
	que.f=que.r=-1;
	insert(&que,5);
	insert(&que,6);
	insert(&que,7);
	insert(&que,8);
	print(&que);
	printf("\n\n");
	del(&que,'f');
	print(&que);
	printf("\n\n");
	del(&que,'r');
	printf("\n\n");
	print(&que);	
}

