#include<bits/stdc++.h>

using namespace std;
int cnt;
int n,k1,i;
int a[10000];

void solution()
{
    {
        for(int i=1; i<=n; i++) cout << a[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k)
{
    if(k<i) return true;
    else
    {
        for(int j=k-i+1; j<=k-1; j++)
        {
            if(a[j]!=1) return true;
        }
        if(v==1) return false;
        else return true;
    }
}

void Try(int k)
{
    for(int v=0; v<=1; v++)
    {
        if(check(v,k))
        {
            a[k]=v;
            if(k==n) solution();
            else Try(k+1);
        }
    }
}

int main()
{
    cnt=0;
    cin >> n >> i;
    Try(1);
    return 0;
}
