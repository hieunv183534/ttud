#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int n;
vector<int> A[N];
int cnt;
bool visited[N];

void input(){
    int u,v;
    cnt=0;
    cin >> n;
    //memset(visited,false,sizeof(visited));
    for(int i=1; i<=n; i++)
        visited[i]=false;
    for(int i=1; i<n; i++){
        cin >>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void dfs(int u){
    visited[u] = true;
    if(A[u].size()==1){
        cnt++;
        return;
    }

    for(int i=0; i<A[u].size(); i++){
        int v = A[u][i];
        if(!visited[v])
            dfs(v);
    }
}

main(){
    input();
    dfs(1);
    cout << cnt;
}
