#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 100005;
int n,m;
int cnt;
bool visited[N];
vector<int> adj[N];

void input(){
    cin >> n >> m;
    int a,b;
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void dfs(int i){
    visited[i] = true;
    for(int j=0; j<adj[i].size(); j++){
        int v = adj[i][j];
        if(!visited[v])
            dfs(v);
    }
}

void solve(){
    cnt =0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}

main(){
    input();
    memset(visited,false,sizeof(visited));
    solve();
}

