#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int d[N];
int n, cnt;

main(){
    int u,v;
    memset(d,0,sizeof(d));
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    for(int i=2; i<=n; i++){
        if(d[i]==1)
            cnt++;
    }
    cout << cnt;
}
