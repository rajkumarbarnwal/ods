#include <stdio.h>
#include <malloc.h>
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
void traverse_rev(NODE *node)
{
	if(node==NULL)
	{
		return;
	}
	else
	{
	    traverse_rev(node->next);
		printf("%d->", node->info);
	}
	
}

void reverse(NODE **ps)
{
	NODE *p = *ps;
	NODE *r;
	NODE *q;
	r=q=NULL;
	while (p!=NULL)
	{
		q=p->next;
		p->next=r;
		r=p;
		p=q;
	}
	*ps=r;
	
}

void insert_first(NODE **ps)
{
	NODE *new1 = (NODE*)malloc(sizeof(NODE));
	printf("\nenter the no. to be inserted:");
	scanf("%d", &new1->info);
	new1->next=*ps;
	*ps=new1;
}
void insert_last(NODE **ps)
{
	NODE *node = *ps;
	NODE *new1 = (NODE*)malloc(sizeof(NODE));
	printf("\nenter no. to be inserted at last:");
	while (node->next!=NULL)
	{
		node=node->next;
	}
	scanf("%d",&new1->info);
	node->next=new1;
	new1->next=NULL;

}
void insert_atany_point(NODE **ps, int value, int n)
{
	NODE *node = *ps;
	NODE *new1 = (NODE *)malloc(sizeof(NODE));
	int i;
	if(n==1)
	{
		new1->next=*ps;
	    *ps=new1;
	}
	
	for(i=0;i<n-2;i++)
	{
		node=node->next;
		if(node==NULL)
		{
			printf("wrong node number");
		}

	}
	new1->info=value;
	new1->next=node->next;
	node->next=new1;


}
void insert_aftervalue(NODE **ps, int value, int n)
{
	NODE *node = *ps;
	NODE *new1 = (NODE *)malloc(sizeof(NODE));
	while(node->info!=n)
	{
		node=node->next;
		if(node==NULL)
		    printf("wrong node number");
    }
	new1->info=value;
	new1->next=node->next;
	node->next=new1;

}

void delete_first(NODE **ps)
{
	NODE *node = *ps;
	if(node==NULL)
	{
		printf("node is empty");
	}
	*ps=node->next;
	free(node);


}

void delete_node(NODE **ps, int n)
{
	NODE *p=*ps;
	NODE *q;
	int i;
	if(p==NULL)
	{
		printf("node is empty");
	}
	for(i=0;i<n-1;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);

}
void delete_value(NODE **ps, int value)
{
	NODE *p=*ps;
	NODE *q;
	int i;
	while(p->info!=value)
	{
		if(p->next==NULL)
		{
			printf("value not available");
		}
		q=p;
		p=p->next;
		
	}
	q->next=p->next;
	free(p);
}

void delete_last(NODE **ps)
{
	NODE *p=*ps;
	NODE *q;
	int i;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
		
	}
	q->next=NULL;
	free(p);

}

void delete_list(NODE **ps)
{
	NODE *node = *ps;
	NODE *q;
	while(node->next!=NULL)
	{
		q=node;
		node=node->next;
		free(q);

	}
	*ps = NULL;
}
void pair_wise_swap(NODE **ps)
{
	int temp;
	NODE *node = *ps;
	while (node!=NULL && node->next!=NULL)
	{
		temp = node->info;
		node->info = node->next->info;
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
		printf("list is empty");
	}
	while (p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	p->next=(*ps)->next;
	q->next=*ps;
	(*ps)->next=NULL;
	*ps=p;
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
void display_middle(NODE *s)
{
	NODE *p,*q;
	p=q=s;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
		if(q==NULL)
		{
			printf("enter odd no. of elements");
			return;
		}

	}
	printf("%d",p->info);
}
void nthnode_fromend(NODE *s, int n)
{
	NODE *node=s;
	int len=0;
	while(node!=NULL)
	{
		len++;
		node=node->next;

	}
	node=s;
	//printf("length=%d",len);
	if(len<n)
	{
		printf("enter valid node");
		return;
	}
	int i;
	for(i=1;i<=len-n;i++)
	{
		node=node->next;

	}
	printf("%dth node from end is %d",n,node->info);
}

NODE * reverse_group(NODE *s,int k)
{
	NODE *c,*p,*n;
	int i=0;
	c=s;
	p=n=NULL;
	while(c!=NULL && i<k)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
		i++;
	}
	if(n!=NULL)
	{
		s->next=reverse_group(n,k);
	}
	return p;
}
int main()
{
	int value,n;
    NODE *start=NULL;
    start=createList(start);
    traverse(start);
	/*insert_first(&start);
	traverse(start);
	insert_last(&start);
	traverse(start);
	printf("enter value to be inserted and position");
	scanf("%d%d",&value,&n);
	insert_atany_point(&start,value,n);
	traverse(start);*/
	//printf("enter value to be inserted and position");
	//scanf("%d%d",&value,&n);
	//insert_aftervalue(&start,value,n);
	//traverse(start);
	printf("\n");
	//delete_first(&start);
	//traverse(start);
	//scanf("%d", &n);
	//delete_node(&start,n);
	//scanf("%d", &value);
	//delete_value(&start, value);
	//traverse(start);
	//delete_last(&start);
	//delete_list(&start);
	//traverse_rev(start);
	//reverse(&start);
	//traverse(start);
	//pair_wise_swap(&start);
	//move_first_last(&start);
	//traverse(start);
	/*if(FindLoop(start))
	    printf("\nLoop Exist");
	else
	    printf("\nNo Loop");*/
	//display_middle(start);
	/*int k;
	printf("enter nth node number");
	scanf("%d",&k);
	nthnode_fromend(start, k);*/
	int k;
	scanf("%d",&k);
	start=reverse_group(&start,k);
	traverse(start);
	return 0;

}