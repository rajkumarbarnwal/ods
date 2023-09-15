//Doubly Linked List
#include<stdio.h>
#include<malloc.h>
typedef struct ListNode
{
	struct ListNode *prev;
	int info;
	struct ListNode *next;
}NODE;
void createList(NODE **ps)
{
	int n,i;
	NODE *node;
	printf("Enter no of nodes to create: ");
	scanf("%d",&n);
	printf("\nEnter values for new nodes: ");
	for(i=1;i<=n;i++)
	{
		if((*ps)==NULL)
		{
			*ps=(NODE *)malloc(sizeof(NODE));
		    scanf("%d",&(*ps)->info);
			(*ps)->next=NULL;
			(*ps)->prev=NULL;
			node=*ps;	
		}
		else
		{
			node->next=(NODE *)malloc(sizeof(NODE));
			node->next->prev=node;
			node=node->next;
		    scanf("%d",&node->info);
			node->next=NULL;
		}
	}
}
void traverse(NODE *node)
{
	if(node==NULL)
	{
	    printf("List is empty");
	    return;
	}
	while(node->next!=NULL)
	{
		printf("%d->",node->info);
		node=node->next;
	}
	while(node!=NULL)
	{
		printf("%d->",node->info);
		node=node->prev;
	}
	
}
void insert_first(NODE **ps,int val)
{
	NODE *new1;
	new1=(NODE *)malloc(sizeof(NODE));
	new1->info=val;
	new1->prev=NULL;
	new1->next=*ps;
	(*ps)->prev=new1;
	*ps=new1;
}
void insert_last(NODE **ps,int val)
{
	NODE *new1;
	NODE *node=*ps;
	while(node->next!=NULL)
		node=node->next;
	new1=(NODE *)malloc(sizeof(NODE));
	new1->info=val;
	new1->next=NULL;
	new1->prev=node;
	node->next=new1;
}
void delete_first(NODE **ps)
{
	NODE *node=*ps;
	if(node==NULL)
	{
		printf("\nList is Empty");
		return;
	}
	if(node->next==NULL)
	{
		*ps=NULL;
	}
	else
	{
	 *ps=node->next;
	(*ps)->prev=NULL;
	}
	free(node);
}
void delete_last(NODE **ps)
{
	NODE *node=*ps;
	if(node==NULL)
	{
		printf("\nList is Empty");
		return;
	}
	while(node->next!=NULL)
		node=node->next;
	if(node->prev==NULL)
	{
		*ps=NULL;
	}
	else
		node->prev->next=NULL;
	free(node);
}
int main()
{
	NODE *start=NULL;
	int value;
	createList(&start);  //start=createList(start)
	traverse(start);
	//printf("\nEnter value to insert as last node: ");
	//scanf("%d",&value);
	//insert_first(&start,value);
	//insert_last(&start,value);
	printf("\n");
	delete_last(&start);
	traverse(start);
	
}
