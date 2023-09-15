#include<stdio.h>
#include<malloc.h>
typedef struct list
{
	int info;
	struct list *next;
}NODE;
void createList(NODE **ps,NODE **pl)
{
	NODE *new1;
	char ch;
	do
	{
		new1=(NODE *)malloc(sizeof(NODE));
		printf("\nEnter value for new Node:");
		scanf("%d",&new1->info);
		if(*ps==NULL)
		{
			*ps=*pl=new1;
			new1->next=*ps;
		}
		else
		{
			(*pl)->next=new1;
			*pl=(*pl)->next;
			(*pl)->next=*ps;
		}
		printf("\nDo you want to create more node: ");
		scanf(" %c",&ch);
	}while(ch=='Y' || ch=='y');
}
void traverse(NODE *s)
{
	NODE *node=s;
	if(s==NULL)
	{
		printf("List is Empty");
		return;
	}
	do
	{
		printf("%d->",node->info);
		node=node->next;
	}while(node!=s);
}
void insert_first(NODE **ps,NODE **pl)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("Enter value for new node: ");
	scanf("%d",&new1->info);
	new1->next=*ps;
	*ps=new1;
	(*pl)->next=*ps;
}
void insert_last(NODE **ps,NODE **pl)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("Enter value for new node: ");
	scanf("%d",&new1->info);
	new1->next=*ps;
	(*pl)->next=new1;
}
void insert_after_value(NODE **ps,NODE **pl,int n,int value)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	NODE *node=*ps;
	new1->info=value;
	while(node->info!=n)
	{
		node=node->next;
		if(node==*ps)
		{
			printf("\n%d does not exist",n);
			return;
		}
	}
	new1->next=node->next;
	node->next=new1;
	if(node==*pl)
	    *pl=new1;
}
void delete_first(NODE **ps,NODE **pl)
{
	NODE *node=*ps;
	if(*ps==NULL)
	{
		printf("List is empty");
		return;
	}
	(*pl)->next=node->next;
	(*ps)=node->next;
	free(node);
}
void delete_last(NODE **ps,NODE **pl)
{
	NODE *node=*ps,*p;
	if(*ps==NULL)
	{
		printf("List is empty");
		return;
	}
	while(node->next!=*pl)
	    node=node->next;
	p=*pl;
	node->next=*ps;
	*pl=node;
	free(p);
}
void delete_value(NODE **ps,NODE **pl,int val)
{
	NODE *node=*ps,*p,*q;
	if(*ps==NULL)
	{
		printf("List is empty");
		return;
	}
	while(node->info!=val)
	{
		q=node;
		node=node->next;
		if(node==*ps)
		{
			printf("\n%d does not exist",val);
			return;
		}
	}
	p=node;
	if(node==*ps)
	    delete_first(ps,pl);
	else
	   if(node==*pl)
	       delete_last(ps,pl);
	   else
	   {
	   	q->next=p->next;
	   	free(p);
	   }
	   
	
}

int FindLoop(NODE *node)
{
	NODE *p,*q;
	p=q=node;
	while(q!=NULL && p!=NULL && p->next!=NULL)
	{
		q=q->next;
		p=p->next->next;
		if(p==q)
		   return 1;
	}
	return 0;
}
int main()
{
	NODE *start=NULL,*last=NULL;
	int n,val;
	createList(&start,&last);
	traverse(start);
	//insert_first(&start,&last);
	//insert_last(&start,&last);
	//printf("enter value to insert: ");
	//scanf("%d",&val);
	//printf("enter after which value to insert: ");
	//scanf("%d",&n);
	//insert_after_value(&start,&last,n,val);
	//delete_first(&start,&last);
	//delete_last(&start,&last);
	/*printf("\nEnter value to delete: ");
	scanf("%d",&val);
	delete_value(&start,&last,val);
	printf("\n");
	traverse(start);*/
	if(FindLoop(start))
	    printf("\nLoop Exist");
	else
	    printf("\nNo Loop");
}
