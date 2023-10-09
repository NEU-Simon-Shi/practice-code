#include <iostream>
using namespace std;

int main2()
{
    int N;
    int i=0;
    cin>>N;

    if(N==0)
    {
        cout<<N;
        return 0;
    }

    string str1= to_string(N);
    unsigned int len=str1.length();
    int* arr =new int[len];

    while(N!=0)
    {
        arr[i++]=N%8;
        N/=8;
    }

    for(int m=i-1;m>=0;m--) cout<<arr[m];

    return 0;
}