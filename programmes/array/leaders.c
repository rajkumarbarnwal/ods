#include <stdio.h>
void leaders(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j;
        for(int j=i+1; j<n; j++)
        {
           // printf("%d <= %d\n",arr[i],arr[j]);
            if ( arr[i] >= arr[j])
                continue;
        }
        if(j == n)
            printf("%d  ",arr[i]);        
    }
}
int main()
{
    int arr[]={16,17,4,3,5,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    //printf("%d",n);
    leaders(arr,n);
    return 0;

}