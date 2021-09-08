#include<bits/stdc++.h>
using namespace std;
const int NMAX = 1003;
const int TMAX = 102;
int N, T, D;
int a[NMAX],t[NMAX];
int F[NMAX][TMAX];


void input(){
    cin >> N >> T >> D;
    for(int i=1; i<=N; i++)
        cin >> a[i];
    for(int i=1; i<=N; i++)
        cin >> t[i];
}

void solve(){
    int best =0;
    for(int i=1; i<=N; i++){
        for(int j=t[i]; j<=T; j++){
            for(int k=i-1;(k>=i-D&&k>=1); k--)
                F[i][j] = max(F[i][j],F[k][j-t[i]]);
            F[i][j]+=a[i];
            best = max(best,F[i][j]);
        }
    }
    cout << best;
}

main(){
    input();
    solve();
}

