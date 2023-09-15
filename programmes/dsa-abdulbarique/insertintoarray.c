#include <stdio.h>
#define max 2;
typedef struct array{
    int A[10];
    int length;
    int size;
}ARRAY;
ARRAY display(ARRAY arr)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        printf("%d  ",arr.A[i]);
    }
}
int main()
{
    ARRAY arr1[10];
    arr1->length=5;
    arr1->size=10;
    int i;
    for(i=0;i<arr1->length;i++)
    {
        printf("enter array: ");
        scanf("%d",&arr1[i]);
    }
    display(arr1[5]);
    return 0;

}