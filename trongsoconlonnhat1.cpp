#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n;
int a[N];
bool visited[N];
int iMem[N];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}

int solve(int i){
    if(i==1)
        return a[i];
    if(visited[i])
        return iMem[i];
    int res = max(a[i],a[i]+solve(i-1));
    iMem[i] = res;
    visited[i] = true;
    return res;
}


main(){
    input();
    memset(visited,false,sizeof(visited));
    int res = solve(n);
    cout << res;
}
