#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100];
int t;
int cnt;

bool check(int v, int k){
    if(k<n) return true;
    return (t+v==m);
}

void solution(){
    cnt++;
    cout << cnt << ":";
    for(int i=1;i<=n; i++) cout << a[i] <<" ";
    cout << endl;
}

void Try(int k){
    for(int v=1; v<=m-t-(n-k);v++){
        if(check(v,k)){
            a[k] = v;
            t=t+v;
            if(k==n) solution();
            else Try(k+1);
            t=t-v;
        }
    }
}



int main(){
    n=4;
    m=7;
    t=0;
    cnt=0;
    Try(1);

    return 0;
}
