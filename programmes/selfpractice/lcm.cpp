#include <iostream>
using namespace std;
int main()
{
    int i=0,lcm,a,b;
    cout<<"enter the values";
    cin>>a>>b;
    lcm = ( a > b ) ? a:b;
    while(1)
    {
        if(lcm%a==0&&lcm%b==0)
        {
            cout<<lcm;
            break;
        }
        lcm++;

    }

    
}
