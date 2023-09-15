#include<stdio.h>
#include<conio.h>
#define size 5
typedef struct queue
{
	int q[size];
	int f,r;
}irqueue;


void del(irqueue *p)
{
	if(p->f==-1)
		printf("Que is empty.");
	else
	{
		printf("Deleted item=%d",p->q[p->f]);								
		if(p->f==p->r)
			p->f=p->r=-1;
		else
			++p->f;
	}
}
void insert(irqueue *p,char side,int item)
{
	//write the code here
	if(p->f==0 && p->r==size-1)
		printf("Queue is full");
	else if(p->f==-1 && (side=='f' || side=='F' || side=='r' || side =='R'))
	{
		++p->f;
		p->q[++p->r]=item;
	}	
	else if(side=='f' || side == 'F')
	{
		if(p->f==0)
			printf("Front side is full, insertion is not possible at front end.\n");
		else
		{
			--p->f;
			p->q[p->f]=item;
		}
	}
	else if(side=='r' || side == 'R')
	{
		if(p->r==size-1)
			printf("Rear end is full, insertion is not possible at rear end.\n");
		else
		{
			p->r++;
			p->q[p->r]=item;
		}
	}	
	else
		printf("\nWrong side is selected\n");
}
void disp(irqueue *p)
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
	char side;
	int choice,item;
	que.f=que.r=-1;
	do
	{
		printf("\n1.Insert");
		printf("\n2.del");
		printf("\n3.disp");
		printf("\n4.exit");
		printf("\nEnter ur choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter an item:");
					scanf("%d",&item);
					printf("Enter the side:");
					side=getche();
					insert(&que,side,item);
					break;
			case 2:del(&que);break;
			case 3:disp(&que);break;
			case 4:break;
			default:printf("\nWrong choice.");
		}
	}while(choice!=4);
	printf("\nProgram end.");	
}

