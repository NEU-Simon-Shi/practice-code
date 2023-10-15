/*#include <iostream>
using namespace std;

int main()
{
    int n,m;  //pt1为遍历arr2的指针
    cin>>n>>m;
    int* arr1=new int[n];
    int* arr2=new int[m];
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];

    for(int pt1=0;pt1<m;pt1++)
    {
        int pt2=0;  //pt2为二分法小的数字
        int pt3=n-1;  //pt3为二分法大的数字
        while(pt2!=pt3)  //pt2和pt3重合时停止循环，能求出相同数字第一位
        {
            int mid = (pt3 + pt2) >> 1;  //mid为二分法中间的数字，指向所求
            if (arr2[pt1]<=arr1[mid]) pt3 = mid;
            else pt2 = mid;

            if ((pt3 - pt2) == 1)
            {
                if (arr2[pt1] == arr1[pt2]) break;
                if (arr2[pt1] == arr1[pt3])
                {
                    pt2 = pt3;
                    break;
                }
                else break;
            }
        }
        if(arr1[pt2]==arr2[pt1]) cout<<pt2+1<<' ';
        else cout<<"-1"<<' ';
    }

    delete[] arr1;
    delete[] arr2;
    return 0;
}
*/