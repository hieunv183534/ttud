#include<bits/stdc++.h>
using namespace std;
const int N = 102;
int n,m;
int a[N];
int cnt;

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}

void solution(){
    if(m==0)
        cnt++;
}

void Try(int k){
    for(int v=a[k]; v<=m; v+=a[k]){
        m=m-v;
        if(k==n) solution();
        else Try(k+1);
        m=m+v;
    }
}

main(){
    input();
    cnt=0;
    Try(1);
    cout << cnt;
}
