/*#include <iostream>
using namespace std;

int loop(int x);

int main()
{
    int a,b;
    cin>>a>>b;

    if(a%2!=0)
    {
        for(int m=a+1;m<=b;m+=2)
            if(loop(m)==1) cout<<m<<endl;
    }

    else
    {
        for(int n=a;n<=b;n+=2)
            if(loop(n)==1) cout<<n<<endl;
    }

    return 0;
}

int loop(int x)
{
    string str= to_string(x);
    unsigned int num=str.length();
    for(unsigned int i=0;i<str.length()/2;i++)
    {
        if(str[i]!=str[num-1]) return 0;
        num--;
    }
    return 1;
}
*/