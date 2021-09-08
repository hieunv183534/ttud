#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int n;
vector<int> A[N];
int p[N];

void input(){
    int u,v;
    cin>>n;
    memset(p,-1,sizeof(p));
    for(int i=1; i<n; i++){
        cin >>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void dfs(int u){
    for(int i=0; i<A[u].size(); i++){
        int v = A[u][i];
        if(p[v]!=-1)
            continue;
        else{
            p[v] = u;
            dfs(v);
        }
    }
}

main(){
    input();
    p[1]=0;
    dfs(1);
    for(int i=2; i<=n; i++)
        cout << p[i] << " ";
}
