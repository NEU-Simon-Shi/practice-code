#include <iostream>
#include <iomanip>
using namespace std;

int main1()
{
    int f;
    cin>>f;

    cout<<fixed<<setprecision(1)<<5*(f-32)/9.0;

    return 0;
}
