/*#include <iostream>
using namespace std;

int sum(int x);

int main()
{
    int x=0;
    cin>>x;

    cout<<sum(x);

    return 0;
}

int sum(int x)
{
    int sum1=0;
    if(x/10==0) return x;
    else
    {
        while (x/10!=0)
        {
            sum1+=x%10;
            x/=10;
        }
        sum1+=x;
        return sum1;
    }
}
*/