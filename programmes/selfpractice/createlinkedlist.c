#include <stdio.h>
typedef struct Node
{
    int info;
    struct Node *next;
}NODE;
NODE * create_node(NODE *ps)
{
    NODE *node;
    char ch;
    do
    {
        if(ps==NULL)
        {
            ps = (NODE *)malloc(sizeof(NODE));
            printf("enter value for new node\n");
            scanf("%d", &ps->info);
            ps->next=NULL;
            node=ps;
        }
        else
        {
            node->next = (NODE *)malloc(sizeof(NODE));
            node=node->next;
            printf("enter value for new node\n");
            scanf("%d",&node->info);
            node->next=NULL;
        }
        printf("do you want to create more node:");
        scanf(" %c", &ch);
    }while (ch=='Y' || ch=='y');
    return ps;
}
/*void traverse(NODE *node)
{
    while(node!=NULL)
    {
        if(node->next==NULL)
			printf("%d",node->info);
		else
		    printf("%d->",node->info);
        printf("\n");
        node=node->next;
    }
}*/
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
int main()
{
    NODE *start=NULL;
    start=create_node(&start);
    traverse(start);
}