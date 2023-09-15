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
            printf("\nenter value for new node:");
            scanf("%d",&s->info);
            s->next=NULL;
            node=s;
        }
        else
        {
            node->next=(NODE *)malloc(sizeof(NODE));
            node=node->next;
            printf("enter value for new node");
            scanf("%d",&node->info);
            node->next=NULL;
        }
        printf("do you want to create more node:");
        scanf(" %c", &ch);
    }while (ch=='Y' || ch=='y');
    return s;
}
void traverse(NODE *node)
{
    if(node==NULL)
    {
        printf("list is empty\n");
        return;
    }
    while (node!=NULL)
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
    start=createList(start);
    traverse(start);
}