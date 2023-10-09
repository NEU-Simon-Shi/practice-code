#include <iostream>
using namespace std;

int main2()
{
    int x=0;
    cin>>x;
    if(x>99&&x<1000)
    {
        if(x%100==0) cout<<x/100;
        else
        {
            cout<<x%10;
            x/=10;
            cout<<x%10;
            x/=10;
            cout<<x%10;
            x/=10;
        }
    }
    else cout<<"-1";

    return 0;
}