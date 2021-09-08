#include<bits/stdc++.h>
using namespace std;
const int N = 3002;
int n,K;
int a[N], c[N];
int cnt, amax;
int f, f_max;
int x[N];

void input(){
    amax = 0;
    cin >> n >> K;
    for(int i=1; i<=n; i++)
        cin >> c[i];
    for(int i=1; i<=n; i++){
        cin >> a[i];
        amax = max(amax,a[i]);
    }

}

void updateBest(int k){
    if(k<=K+1){
        f_max = max(f_max,f);
    }
}

void Try(int k){
    for(int v=x[k-1]+1; v<=x[k-1]+a[x[k-1]]; v++){
        x[k] = v;
        f += c[v];
        if(v==n) updateBest(k);
        else{
            if( ((K+1-k)*amax+v)>=n )
                Try(k+1);
        }
        f -= c[v];
    }
}

main(){
    input();
    cnt=0;
    f=0;
    f_max =c[1];
    x[1]=1;
    Try(2);
    if(f_max==0)
        cout << -1;
    else cout << f_max;
}
