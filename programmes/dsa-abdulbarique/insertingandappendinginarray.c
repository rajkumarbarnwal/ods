#include<stdio.h>
struct Array
{
 int A[10];
 int size;
 int length;
}; 
 void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }
 void Append(struct Array *arr,int x)
 {
 if(arr->length<arr->size)
 arr->A[arr->length++]=x;
 }
 void Insert(struct Array *arr,int index,int x)
 {
 int i;
 
 if(index>=0 && index <=arr->length)
 {
 for(i=arr->length;i>index;i--)
 arr->A[i]=arr->A[i-1];
 arr->A[index]=x;
 arr->length++;
 }
 }

 int delete(struct Array *arr, int index) 
 {
     int x=0;
     int i;
     if (arr>=0 && index<arr->length)
     {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
     }
  
     return 0;
 }

 int linear_search(struct Array arr, int key)
 {
     int i;
     for(i=0;i<arr.length;i++)
     {
         if(key==arr.A[i])
         {
             return i;
         }
     }
     return -1;

 }

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int linear_search1(struct Array *arr, int key)
 {
     int i;
     for(i=0;i<arr->length;i++)
     {
         if(key==arr->A[i])
         {
             swap(&arr->A[i],&arr->A[0]);
             return i;
         }
     }
     return -1;

 }
int main()
{
struct Array arr1={{2,3,4,5,6},10,5};
//Append(&arr1,15);
//Insert(&arr1,0,12);
//printf("%d\n",delete(&arr1,4));
//printf("%d",linear_search(arr1,5)+1);
printf("%d",linear_search1(&arr1,6)+1);
Display(arr1);
return 0; }