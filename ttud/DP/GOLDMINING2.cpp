#include<bits/stdc++.h>
using namespace std;
const int N = 100002;
int n, k1, k2;
int a[N];
int F[N];

void input(){
    cin >> n >> k1 >> k2;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}

void solve(){
    int best =0;
    for(int i=1; i<=n; i++){
        for(int k=i-k1; (k>=i-k2&&k>=0); k--){
            F[i] = max(F[i],F[k]);
        }
        F[i]+= a[i];
        best = max(best,F[i]);
    }
    cout << best;
}

main(){
    input();
    solve();
}
