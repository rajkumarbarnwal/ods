#include<stdio.h>
typedef struct Node
{
	int info;
	struct Node *next;
}NODE;
NODE * createList(NODE *s)
{
	NODE *node;
	char ch;
	do{
		if(s==NULL)
		{
			s=(NODE *)malloc(sizeof(NODE));
			printf("\nEnter value for new node: ");
			scanf("%d",&s->info);
			s->next=NULL;
			node=s;
		}
		else
		{
			node->next=(NODE *)malloc(sizeof(NODE));
			node=node->next;
			printf("\nEnter value for new node: ");
			scanf("%d",&node->info);
			node->next=NULL;	
		}
		printf("Do you want to create more node : ");
		scanf(" %c",&ch);
	}while(ch=='Y' || ch=='y');
	return s;
}
void insert_node(NODE **ps,int value,int n)
{
    NODE *node=*ps;
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	int i;
	if(n==1)
	{
		new1->info=value;
		new1->next=*ps;
		*ps=new1;
	}
	else
	{
	for(i=1;i<=n-2;i++)
	{
	    node=node->next;
	    if(node==NULL)
	    {
	    	printf("Wrong node number");
	    	return;
		}
	}
	new1->info=value;
	new1->next=node->next;
	node->next=new1;
    }
}
void insert_aftervalue(NODE **ps,int value,int n)
{
    NODE *node=*ps;
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	while( node->info!=n)
	{
	    node=node->next;
	    if(node==NULL)
	    {
	    	printf("Wrong node value");
	    	return;
		}
	}
	new1->info=value;
	new1->next=node->next;
	node->next=new1;
}
void insert_last(NODE **ps)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	NODE *node=*ps;
	while(node->next!=NULL)
	{
		node=node->next;
	}
	printf("enter value for new node: ");
	scanf("%d",&new1->info);
	new1->next=NULL;
	node->next=new1;
}
void insert_first(NODE **ps)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("enter value for new node: ");
	scanf("%d",&new1->info);
	new1->next=*ps;
	*ps=new1;
}
void delete_first(NODE **ps)
{
	NODE *node=*ps;
	if(node==NULL)
	{
		printf("\nList is empty");
		return;
	}
	*ps=node->next;
	free(node);
}
void delete_last(NODE **ps)
{
	NODE *p=*ps;
	NODE *q;
	if(p==NULL)
	{
		printf("\nList is empty");
		return;
	}
	if(p->next==NULL)
	{
		free(p);
		*ps=NULL;
	}
	else
	{
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		free(p);
	}
}
void delete_value(NODE **ps,int value)
{
	NODE *p=*ps;
	NODE *q;
	int i;
	if(p==NULL)
	{
		printf("\nList is empty");
		return;
	}
	if(p->info==value)
	{
		delete_first(ps);
		return;
	}
	while(p->info!=value)
	{
		q=p;
		p=p->next;
		if(p==NULL)
		{
			printf("\n%d does not exist in list",value);
			return;
		}
	}
	q->next=p->next;
	free(p);
}
void delete_node(NODE **ps,int n)
{
	NODE *p=*ps;
	NODE *q;
	int i;
	if(p==NULL)
	{
		printf("\nList is empty");
		return;
	}
	if(n==1)
	{
		delete_first(ps);
		return;
	}
	for(i=1;i<=n-1;i++)
	{
		q=p;
		p=p->next;
		if(p==NULL)
		{
			printf("\nWrong node number");
			return;
		}
	}
	q->next=p->next;
	free(p);
}
void delete_list(NODE **ps)
{
	NODE *q,*p;
	p=*ps;
	if(p==NULL)
	{
		printf("\nList is empty");
		return;
	}
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*ps=NULL;
}
void traverse(NODE *node)
{
	if(node==NULL)
	{
		printf("List is Empty");
		return;
	}
	while(node!=NULL)
	{
		if(node->next==NULL)
			printf("%d",node->info);
		else
		    printf("%d->",node->info);
		node=node->next;
	}
}
void traverseRev(NODE *node)
{
	if(node==NULL)
	   return;
	else
	{
		traverseRev(node->next);
		printf("%d->",node->info);
	}
	   
}
void reverse_list(NODE **ps)
{
	NODE *p,*q,*r;
	p=*ps;
	r=q=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=r;
		r=p;
		p=q;
	}
	*ps=r;
}
void pair_wise_swap(NODE **ps)
{
	int temp;
	NODE *node=*ps;
	while(node!=NULL && node->next!=NULL)
	{
		temp=node->info;
		node->info=node->next->info;
		node->next->info=temp;
		node=node->next->next;
	}
}
void move_first_last(NODE **ps)
{
	NODE *p,*q;
	p=*ps;
	if(p==NULL)
	{
		printf("List is empty: ");
		return;
	}
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	p->next=(*ps)->next;
	q->next=*ps;
	(*ps)->next=NULL;
	*ps=p;
    
}
void displaymiddle(NODE *s)
{
	NODE *p,*q;
	p=q=s;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
		if(q==NULL)
		{
			printf("\nenter odd no of elements");
			return;
		}
	}
	printf(" %d ",p->info);
}
void nthnode_fromend(NODE *s,int n)
{
	NODE *node=s;
	int len=0,i;
	while(node!=NULL)
	{
		len++;
		node=node->next;
	}
	node=s;
	if(len<n)
	{
		printf("\ninvalid node number");
		return;
	}
	for(i=1;i<=len-n;i++)
	     node=node->next;
	printf("\n%dth node from end is %d ",n,node->info);
}
int main()
{
	NODE *start=NULL;
	int value,n;
	start=createList(start);  
	traverse(start);
	//insert_first(&start);
	//insert_last(&start);
	//printf("\nEnter value and node no to insert: ");
	//scanf("%d%d",&value,&n);
	//insert_node(&start,value,n);
	//printf("\nEnter value to insert: ");
	//scanf("%d",&value);
	//printf("\nEnter node value after which to insert: ");
    //scanf("%d",&n);
	//insert_aftervalue(&start,value,n);
	//delete_first(&start);
	//delete_last(&start);
	//printf("\nEnter node value to delete: ");
	//scanf("%d",&value);
	//delete_value(&start,value);
	//printf("\nLinked List after deletion of node: ");
	//printf("\n Middle of the Linked List : ");
	//displaymiddle(start);
	//traverseRev(start);
	//pair_wise_swap(&start);
	//move_first_last(&start);
	//traverse(start);
	printf("\nEnter the node no from end to display: ");
	scanf("%d",&n);
	nthnode_fromend(start,n);
}
