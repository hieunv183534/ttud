#include<bits/stdc++.h>

using namespace std;
const int N=100;
int n, m, k1;
int c[N][N];
bool visited[N];
int cnt;
int x[N];

void input()
{
    cin >> n >> k1;
    cin >> m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin >> a >> b;
        c[a][b]=1;
        c[b][a]=1;
    }
}

bool check(int v, int k)
{
    if(!visited[v])
    {
        if(k==1) return true;
        else
        {
            if(c[x[k-1]][v]==1) return true;
        }
    }
    return false;
}

void solution()
{
    cnt++;
}

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if(check(v,k))
        {
            x[k] = v;
            visited[v] = true;
            if(k==(k1+1)) solution();
            else
            {
                Try(k+1);
            }
            visited[v] = false;
        }
    }
}

int main()
{
    input();
    for(int i=1; i<=n; i++)
        visited[i] = false;
    cnt=0;
    for(int i=1; i<=n; i++)
        c[0][i] =1;
    Try(1);
    cout << cnt;
    return 0;
}
