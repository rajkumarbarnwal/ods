#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int maxfright(int arr[], int n)
{
    int max = arr[n-1];
    arr[n-1]=-1;
    for(int i=n-2;i>0;i--)
    {
        int temp=arr[i];
        arr[i]=max;
        if(max<temp)
        {
            max=temp;

        }
    }
    return 0;
}
void pmaxfright(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

}
int main()
{
    int arr[]={16,17,3,4,5,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    maxfright(arr,n);
    pmaxfright(arr,n);
}