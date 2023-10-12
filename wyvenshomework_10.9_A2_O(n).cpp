#include <iostream>
using namespace std;

int main()
{
    int sums[100]={0};
    int m=0;
    while(!cin.eof())
    {
        cin>>sums[m++];
    }

    if(m<3)
    {
        cout<<"0"<<endl;
        return 0;
    }

    int num1=0,num2=1,num3=m-1,pt=m-1;
    int ans=(sums[num1]-sums[num2])*sums[num3];
    for(int i=1;i<m-1;i++)
    {
        if(sums[i]>sums[num1]&&i<num3-1)
        {
            num1=i;
            if((sums[num1]-sums[num1+1])*sums[num3]<ans)
            {
                num2=num1+1;
                continue;
            }
            if((sums[num1]-sums[num1+1])*sums[num3]>ans)
            {
                ans=(sums[num1]-sums[num1+1])*sums[num3];
                num2=num1+1;
                continue;
            }
        }
        if(sums[i]<sums[num2]&&i<num3)
        {
            num2=i;
            ans=(sums[num1]-sums[num2])*sums[num3];
            continue;
        }

        if(sums[num3]<sums[--pt]&&pt>i)
        {
            num3=pt;
        }
    }

    if(ans<0)	cout<<"0"<<endl;
    else	cout<<ans<<endl;

    return 0;
}