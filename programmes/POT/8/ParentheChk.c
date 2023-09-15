
#include<stdio.h>
#include<conio.h>
#define max 20
void push(char ch);
void pop(void);
int stack[max],top=-1;
void push(char ch)
{
	if(top == max-1)
		printf("\n overflow error ");
	else
		stack[++top]=ch;
}
void pop(void)
{
	top--;
}
void main()
{
	int i;		
	char exp[20],flag=0;
	printf("\nEnter an infix notation :");
	gets(exp);
	for(i=0;exp[i]!='\0';i++)
	{
		switch(exp[i])
		{
			
			case '(':	push(exp[i]);	
						break;
			case ')':
				if(top ==-1)
				{
					printf("The parenthesis missing is '(' \n");
					flag=1;
				}
				else
					pop();
			break;
		}
	}
	if(top ==-1 && flag == 0)
		printf("correct expression");
	else
		for(i=top;i>=0;i--)
			printf("the parenthesis missing is ')' \n");
}



