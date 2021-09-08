#include<bits/stdc++.h>

using namespace std;
const int MAX=20005;

int main()
{
    int n, m,M;
    cin >> n >> m >> M;
    int cnt =0;
    int a[MAX];
    int sum[MAX]; // luu sum tu 1 den i
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sum[1] = a[1];
    sum[0] =0;
    for(int i=2; i<=n; i++)
    {
        sum[i] = sum[i-1] +a[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            int tmp = sum[j]-sum[i-1];
            if(tmp>=m&&tmp<=M) cnt++;
        }
    }

    cout << cnt;
    return 0;
}
