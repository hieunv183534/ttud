#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int n,m;
vector<int> A[N];
int d[N];
queue<int> Q;

void input()
{
    memset(d,0,sizeof(d));
    int u,v;
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        cin >> u >> v;
        A[u].push_back(v);
        d[v]++;
    }
}

void solve()
{
    for(int i=1; i<=n; i++)
        if(d[i]==0)
            Q.push(i);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        for(int i=0; i<A[u].size(); i++)
        {
            int v = A[u][i];
            d[v] -=1;
            if(d[v]==0)
                Q.push(v);
        }
    }
}

main()
{
    input();
    solve();
}
