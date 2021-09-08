#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+1;
int n,k1,k2;
int a[N];
int iMem[N];

void input(){
    cin >> n >> k1 >> k2;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}

int dp(int i){
    if(i<=k1)
        return a[i];
    if(iMem[i]!=-1)
        return iMem[i];
    int res =0;
    for(int k=k1; k<=k2; k++){
        res = max(res,dp(i-k));
    }
    res =  res + a[i];
    iMem[i] = res;
    return res;
}

main(){
    input();
    memset(iMem, -1, sizeof(iMem));
    int res = 0;
    for(int i=0; i<=k2-1; i++)
        res = max(res,dp(n-i));
    cout << res;
}
