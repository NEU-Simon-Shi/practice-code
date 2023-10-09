/*#include <iostream>
#include <cstring>
using namespace std;

void invert(int A,char str[][100]);

int main()
{
    int N;
    cin>>N;
    char str[N][100];
    for(int i=0;i<N;i++)
    {
        cin>>str[i];
        invert(i,str);
    }

    for(int i=0;i<N;i++) cout<<str[i]<<endl;

    return 0;
}

void invert(int A,char str[][100])
{
    unsigned int m=strlen(str[A]);
    for(unsigned int k=0;k<strlen(str[A])/2;k++)
    {
        char n=str[A][m-1];
        str[A][m-1]=str[A][k];
        str[A][k]=n;
        m--;
    }
}
*/