#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minmdist(int arr[], int n, int x, int y)
{
    int mindist=__INT_MAX__;

    for(int i=0; i<n;i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if( (x==arr[i]&&y==arr[j]||y==arr[i]&&x==arr[j])&& mindist > abs(i-j))
            {
                mindist=abs(i-j);
            }
        }
    }
    return mindist;

}
int main()
{
    int arr[]={3,5,4,6,7,1,2,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=3;
    int y=8;
    printf("the value of distance between x and y is %d", minmdist(arr,n,x,y));
}