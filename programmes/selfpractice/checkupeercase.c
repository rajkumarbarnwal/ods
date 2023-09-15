#include <stdio.h>
int main()
{ 
    char ch;
    printf("enter the character value:");
    scanf("%c",&ch);
    if(ch>=65&&ch<=90)
    {
        printf("%c is upper case",ch);
    }
    else if (ch>90&&ch<=122)
    {
        printf("%c is lower case",ch);
    }
    else if (ch>=48&&ch<=57)
    {
        printf("%c is a number",ch);
    }
    else{
        printf("%c is a special character",ch);
    }
    
    
}