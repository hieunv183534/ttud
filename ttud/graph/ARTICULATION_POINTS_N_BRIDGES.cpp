#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int n,m;
vector<int> A[N];
bool visited[N];
int num[N];
int low[N];
int t;
int soCau, soKhop;
int root;
int numChildRoot;

void input()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void dfs(int s, int ps)
{
    t++;
    num[s]=t;
    low[s]=num[s];
    visited[s]= true;
    for(int i=0; i<A[s].size(); i++)
    {
        int v = A[s][i];
        if(v==ps) continue;
        if(visited[v])
        {
            low[s] = min(low[s], num[v]);
        }
        else
        {
            dfs(v,s);
            low[s] = min(low[s], low[v]);
            if(low[v]>num[s])
            {
                soCau++;
            }
            if(s==root)
                numChildRoot++;
            else
            {
                if(low[v]>=num[s])
                    soKhop++;
                cout << s << "__";
            }
        }
    }
}

void solve()
{
    t=0;
    for(int s=1; s<=n; s++)
    {
        if(!visited[s])
        {
            root = s;
            numChildRoot=0;
            dfs(root,-1);
            if(numChildRoot>=2)
            {
                soKhop++;
                cout << root << "__";
            }
        }
    }
    //cout << soKhop-1 << " " << soCau;
}

main()
{
    input();
    soCau =0;
    soKhop =0;
    root =-1;
    //memset(visited, false, sizeof(visited));
    for(int i=1; i<=n; i++)
        visited[i] = false;
    solve();
    cout<< endl;
    for(int i=1; i<= n; i++){
        cout << num[i] << " ";
    }

    cout<< endl;
    for(int i=1; i<= n; i++){
        cout << low[i] << " ";
    }

    cout<< endl;
}
