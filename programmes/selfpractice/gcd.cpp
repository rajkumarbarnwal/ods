#include <iostream>
using namespace std;
int main()
{
    int i=0,gcd,a,b;
    cout<<"enter number";
    cin>>a>>b;
    gcd = (a<b)?a:b;
    while(1)
    {
        if(a%gcd==0&&b%gcd==0)
        {
            cout<<gcd;
            break;

        }
        gcd--;

    }

}