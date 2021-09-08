#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int K;

struct edge{
    int u;
    int v;
    int w;
    edge(int _u, int _v, int _w){
        u=_u;
        v=_v;
        w=_w;
    }
};

int n,m;
vector<edge> E;
vector<edge> T;

// disjoint-set
int p[N];
int r[N];
long long res;

void makeSet(int x){
    p[x]=x;
    r[x]=0;
}

void unify(int x, int y){
    if(r[x]>r[y]) p[y]=x;
    else{
        p[x]=y;
        if(r[x]==r[y])
            r[y]=r[y]+1;
    }
}

int find_(int x){
    if(x!=p[x])
        p[x] = find_(p[x]);
    return p[x];
}

bool compare(edge& e1, edge& e2){
    return e1.w < e2.w;
}

void solve(){
    sort(E.begin(),E.end(),compare);
    for(int i=1; i<=n; i++){
        makeSet(i);
    }
    for(int i=0; i<m; i++){
        int pu = find_(E[i].u);
        int pv = find_(E[i].v);
        if(pu!=pv){
            unify(pu,pv);
            T.push_back(E[i]);
            res+= E[i].w;
            if(T.size()==K)
                break;
        }
    }
    if(T.size()<K) res =-1;
    cout << res;
}

void input(){
    int u,v,w;
    cin>>n>>m>>K;
    for(int i=1; i<=m; i++){
        cin >>u>>v>>w;
        E.push_back(edge(u,v,w));
    }
}

main(){
    input();
    solve();
}
