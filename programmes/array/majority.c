#include <stdio.h>
void majority(int arr[], int n)
{
    int maxcount=0;
    int index=-1;
    for(int i=0; i<n;i++)
    {  int count=0;
        for(int j=0; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
            if (count > maxcount)
            {
                maxcount=count;
                index=i;
            }

        }
    }
    if (maxcount > n/2)
    {
        printf("%d",arr[index]);

    }
    else{
        printf("invalid");
    }
}
int main()
{
    int arr[]={3,5,6,5,1,5,5,6,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    majority(arr,n);
}