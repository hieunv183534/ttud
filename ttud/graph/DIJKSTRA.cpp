#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+1;
const int INF = 1e9;

struct Arc{
    int node;
    int w;
    Arc(int _node, int _w){
        node = _node;
        w = _w;
    }
};

int n,m;
vector<Arc> A[N];
int d[N];
int s,t;

void input(){
    int u,v,w;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>u>>v>>w;
        A[u].push_back(Arc(v,w));
    }
    cin>>s>>t;
}

void solve(){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    for(int i=1; i<=n; i++){
        d[i] = INF;
    }
    d[s]=0; pq.push(make_pair(d[s],s));
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int u = p.second;
        if(u==t)break;
        for(int i=0; i<A[u].size(); i++){
            int v = A[u][i].node;
            int w = A[u][i].w;
            if(d[v]> d[u]+w){
                d[v] = d[u]+w;
                pq.push(make_pair(d[v],v));
            }
        }
    }
    if(d[t]==INF)
        d[t] = -1;
    cout << d[t];
}

main(){
    input();
    solve();
}
