#include <iostream>
using namespace std;

int main8()
{
    int N;
    int x=0;
    cin>>N;

    for(int i=1;i<N;i++)
    {
        if(N%i==0) x++;
    }

    if(x>1) cout<<"0";
    else cout<<"1";

    return 0;
}