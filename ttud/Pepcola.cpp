#include<bits/stdc++.h>

using namespace std;
const int N=100001;
int n, q;
int c[N];
//giá tại cảu hàng i



int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> c[i];
    sort(c,c+n);
    cin >> q;
    while(q--)
    {
        int a;
        cin >> a;
        int cnt=0;
        if(c[n-1]<=a)
        {
            cnt=n;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(c[i]>a)
                {
                    cnt =i;
                    break;
                }
            }

        }
         cout << cnt << endl;
    }

    return 0;
}
