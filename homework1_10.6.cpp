#include <iostream>
#include <cmath>
using namespace std;

int main1()
{
    int N;
    int sum=0;
    cin>>N;

    cout<<N*pow(10,5)<<endl;
    for(int i=0;i<N;i++)
    {
        sum+=pow(2,i);
    }
    cout<<sum;

    return 0;
}