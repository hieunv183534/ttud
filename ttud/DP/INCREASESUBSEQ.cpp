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
    if(iMem[i]!=0)
        return iMem[i];
    int maxtmp = 0;
    for(int j=1; j<i; ++j){
        if(a[j]<a[i]){
            maxtmp = max(maxtmp,iMem[j]);
        }
    }
    iMem[i] = maxtmp+1;
    return iMem[i];
}

main(){
    input();
    //memset(iMem,-1,sizeof(iMem));
    iMem[1]=1;
    dp(n);
    int res =0;
    for(int i=1; i<=n;i++){
        cout << iMem[i] << "--";
        res = max(res,iMem[i]);
    }
    cout << res;
}
