//2^31=2147483648
/*#include <iostream>
using namespace std;
#define llu long long unsigned

int main()
{
    llu a,b,p,sum=1;
    cin>>a>>b>>p;
    llu a1=a,b1=b;

    if(b==0)
    {
        printf("%llu^%llu mod %llu=1\n",a1,b1,p);
        return 0;
    }

    while(b>1)
    {
        if(b&1)
        {
            b-=1;
            b=b>>1;
            sum*=a;
            sum%=p;
            a*=a;
            a%=p;
        }
        else
        {
            b=b>>1;
            a*=a;
            a%=p;
        }
    }
    sum*=a;
    sum%=p;

    printf("%llu^%llu mod %llu=%llu\n",a1,b1,p,sum);

    return 0;
}
*/