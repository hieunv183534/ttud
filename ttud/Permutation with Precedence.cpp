#include<bits/stdc++.h>
using namespace std;
int n,k1;
int a[100][2];
bool b[100];
int x[100];
int cnt;


void solution()
{
    cnt++;
    for (int i=1; i<=n; i++) cout << x[i] << " ";
    cout << endl;
}

bool check(int v, int k)
{
    if(b[v]==true) return false;
    else
    {
        for(int j=1; j<=k1; j++)
        {
            if(v==a[j][1])
            {
                if(b[a[j][0]]==true) return true;
                else return false;
            }
        }
        return true;
    }
}

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if(check(v,k))
        {
            x[k]=v;
            b[v] = true;
            if(k==n) solution();
            else Try(k+1);
            b[v] = false;
        }
    }
}

main()
{   cnt =0;
    cin >> n >> k1;
    for(int i=1; i<=k1; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for(int i=1; i<=n; i++)
        b[i] = false;
    Try(1);
    cout << cnt;
}
