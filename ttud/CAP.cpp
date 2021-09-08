#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int a[N],b[N];
int cnt;


int main()
{
    cnt=0;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        cin >> m;
        for(int j=1; j<=m; j++)
            cin >> b[j];

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                if(a[i]==b[j]) cnt++;
        }

        cout << cnt;

    }

    return 0;
}
