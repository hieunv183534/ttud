#include<bits/stdc++.h>

using namespace std;
const int NMAX= 1000000;
int n;
int a[NMAX];
int dmax,tmax;

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    dmax =0;
    tmax=0;
    int r1=0,l1 =0;
    int r2=0,l2=0;
    // tính dmax
    int check1 =0, check2=0;
    for(int i=2; i<=n; i++)
    {
        if(a[i]>a[i-1])
        {
            //doi
            if(check1==1)
            {   // đồi đang đi lên và sẽ đi lên tiếp
                l1++;

            }
            else if(check1==0)
            {   // không phải đồi và bắt đầu đi lên
                l1=1;
                check1=1;

            }
            else if(check1==-1)
            {   // đồi đang đi xuống -> ngắt đồi trước, update best và bắt đầu đồi mới đi lên
                dmax = max(dmax,min(l1,r1));
                l1=1;
                r1=0;
                check1=1;
            }
            //tl---------------------------------------------------------------
            if(check2==1)
            {
                r2++;
            }
            else if(check2==0)
            {
                check2=0;
            }
            else if(check2==-1)
            {
                check2 =1;
                r2++;
            }
        }
        else if(a[i]<a[i-1])
        {
            //doi
            if(check1==1)
            {   //đồi đang đi lên và bắt đầu đi xuống
                check1 =-1;
                r1++;
            }
            else if(check1==0)
            {   // không phải đồi nên đi xuống ko tạo ra đồi
                check1=0;
            }
            else if(check1==-1)
            {   //đồi đang đi xuống và tiếp tục đi xuống
                r1++;
            }
            //tl----------------------------------------------------------------
            if(check2==1)
            {
                check2=-1;;
                tmax=max(tmax,min(r2,l2));
                r2=0;
                l2=1;
            }
            else if(check2==0)
            {
                check2=-1;
                l2=1;
            }
            else if(check2==-1)
            {
                l2++;
            }
        }
        else
        {
            //doi
            if(check1==1)
            {   // đồi đang đi lên và ko đi lên nữa-> bỏ đồi này.
                check1 =0;
                l1=0;
                r1 =0;
            }
            if(check1==0)
            {   //không là đồi, vẫn không là đồi
                check1 =0;
                l1=0;
                r1=0;
            }
            if(check1==-1)
            {   // đang đi xuống, không xuống nữa. kết thúc đồi , update best
                check1=0;
                dmax = max(dmax,min(l1,r1));
                l1=0;
                r1=0;
            }
            //tl--------------------------------------------------------------
            if(check2==1)
            {
                check2=0;
                tmax=max(tmax,min(l2,r2));
                r2=0;
                l2=0;
            }
            if(check2==0)
            {
                check2=0;
                r2=0;
                l2=0;
            }
            if(check2==-1)
            {
                check2=0;
                r2=0;
                l2=0;
            }
        }
    }
    if(r1!=0) dmax=max(dmax,min(l1,r1));
    if(r2!=0) tmax=max(tmax,min(l2,r2));
    cout << dmax <<" ";
    cout << tmax ;

    return 0;
}
