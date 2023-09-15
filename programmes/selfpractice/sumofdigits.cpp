#include <iostream>
using namespace std;
int main()
{
    int i=0,n;
    cout<<"enter number";
    cin>>n;
    int sum=0;
    while(n>0)
    {
        sum=sum+(n%10);
        n=n/10;
    }
    cout<<sum;
}