/*#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N=0;
    cin>>N;
    int* arr1=new int[N];
    int* arr2=new int[N-1];

    for(int i=0;i<N;i++)
    {
        cin>>arr1[i];
    }
    sort(arr1,arr1+N);
    if(arr1[N-1]-arr1[0]==0)
    {
        cout<<N;
        return 0;
    }

    for(int i=0;i<N-1;i++)
    {
        arr2[i]=arr1[i+1]-arr1[i];
    }
    sort(arr2,arr2+N-1);

    cout<<(arr1[N-1]-arr1[0])/arr2[0]+1;

    delete[] arr1;
    delete[] arr2;
    return 0;
}
*/