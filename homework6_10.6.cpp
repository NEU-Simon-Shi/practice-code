#include <iostream>
using namespace std;

int main6()
{
    int n=0;
    cin>>n;

    int row=n/2+1;
    int row1=row-1;

    for(int i=0;i<row;i++)
    {
        for(int m=0;m<row1;m++) cout<<" ";
        row1--;
        for(int j=0;j<(i+1)*2-1;j++) cout<<"*";
        cout<<endl;
    }

    return 0;
}
