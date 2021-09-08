#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n;
int res;
//int p[N];
int d[N];

struct Arc{
    int v;
    int w;
    Arc(int _v, int _w){
        v=_v;
        w=_w;
    }
};

vector<Arc> A[N];
bool visited[N];

void input(){
    cin>>n;
    for(int i=1; i<n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        A[u].push_back(Arc(v,w));
        A[v].push_back(Arc(u,w));
    }
}

void bfs(int s){
    queue<int> Q;
    Q.push(s);
    visited[s]=true;
    d[s]=0;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i=0; i<A[u].size(); i++){
            int v = A[u][i].v;
            if(!visited[v]){
                d[v]=d[u]+A[u][i].w;
                Q.push(v);
                visited[v]= true;
            }
        }
    }
}

void solve(){
    memset(visited,false,sizeof(visited));
    memset(d,0,sizeof(d));
    bfs(1);
    int x =1;
    for(int i=1; i<=n; i++){
        if(d[i]>d[x])
            x=i;
    }
    memset(visited,false,sizeof(visited));
    memset(d,0,sizeof(d));
    bfs(x);
    res =0;
    for(int i=1; i<=n; i++){
        if(d[i]>res)
            res = d[i];
    }
    cout << res;
}

main(){
    input();
    solve();
}
