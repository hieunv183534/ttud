#include<bits/stdc++.h>
using namespace std;
const int N = 3e6;
const int INF = 1e9;
int n;
int L[N+1],R[N+1];

inline void read(int &n){
    char c; n=0;
    do{
        c= getchar();
    } while(!isdigit(c));
    do{
        n=n*10+c-48;
        c=getchar();
    } while(isdigit(c));
}

void dp(){
    for(int i=0; i<=N+1; ++i){
        L[i] = -INF;
        R[i] = -INF;
    }
    read(n);
    while(n--){
        int a, b;
        read(a), read(b);
        L[b] = max(L[b],b-a);
        R[a]= max(R[a], b-a);
    }
    for(int i=1; i<=N; ++i) L[i] = max(L[i-1],L[i]);
    for(int i=N; i>=1; --i) R[i] = max(R[i], R[i+1]);
    int res = -INF;
    for(int i=1; i<N; i++) res = max(res, L[i] + R[i+1]);
    cout << res;
}

main(){
    dp();
}
