#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int n;
int a[N];
int iMem[N];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}

int dp(int i){
    if(iMem[i] != -1)
        return iMem[i];
    int res = 1;
    for(int j=1; j<i; ++j){
        if(a[j]<a[i]){
            res = max(res,1+dp(j));
        }
    }
    iMem[i] = res;
    return res;
}

main(){
    input();
    memset(iMem,-1,sizeof(iMem));
    cout << dp(n);
}
