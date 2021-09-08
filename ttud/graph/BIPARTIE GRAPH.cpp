#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int n,m;
vector<int> A[N];
queue<int> Q;
int num[N];
int res;

void input(){
    int u,v;
    res =1;
    memset(num,-1,sizeof(num));
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void bfs(int s){
    num[s] = 1;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i=0; i<A[u].size(); i++){
            int v = A[u][i];
            if(num[v]==-1){
                Q.push(v);
                num[v] = 3-num[u];
            }
            else{
                if((3-num[u])!=num[v]){
                    res = 0;
                    break;
                }
            }
        }
        if(res==0) break;
    }
}

void solve(){
    for(int s=1; s<=n; s++){
        if(num[s]==-1)
            bfs(s);
        if(res==0)
            break;
    }
    cout << res;
}

main(){
    input();
    solve();
}
