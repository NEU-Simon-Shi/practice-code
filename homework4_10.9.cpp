#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main4()
{
    int N;
    double sum=0;
    cin>>N;

    {

        for(int i=1;i<=N;i++)
        {
         sum+=pow(i,2);
        }
        cout<<fixed<<setprecision(0)<<sum;
    }
    return 0;
}