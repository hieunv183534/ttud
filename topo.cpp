#include<bits/stdc++.h>
using namespace std;
const int N = 10003;
const int M = 2e6+1;
int t[N];
int p[N];
int d[N];
int n,m;
vector<int> A[N];
queue<int> Q;
vector<int> C[N];
int res;

void input(){
    int u,v;
    res =0;
    memset(t,-1,sizeof(t));
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin >> d[i];
    }
    for(int i=1; i<=m; i++){
        cin >>u>>v;
        A[v].push_back(u);
        C[u].push_back(v);
        p[v]++;
    }
}

void solve(){
    for(int i=1;i<=n; i++){
        if(p[i]==0){
            Q.push(i);
            t[i]=0;
        }
    }
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i=0; i<A[u].size(); i++){
            int s = A[u][i];
            t[u] = max(t[u],t[s]+d[s]);
        }
        //t[u]++;
        for(int i=0; i<C[u].size(); i++){
            int v = C[u][i];
            p[v]--;
            if(p[v]==0) Q.push(v);
        }
    }
    for(int i=1; i<=n; i++){
            //cout << t[i]+d[i]<<" ";
        res= max(res,t[i]+d[i]);
    }
    cout << res;
}

main(){
    input();
    solve();
}
