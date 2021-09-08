#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int n;
int a[N];
int iMem[N];


void input(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}

int dp(int i){
    if(i==1){
        //iMem[i]=1;
        return 1;
    }
    if(iMem[i]!=0)
        return iMem[i];
    int res=1;
    for(int j=1; j<i; j++){
        if(a[i]==a[j]+1){
            res = max(res,1+dp(j));
        }
    }
    iMem[i]=res;
    return res;
}

main(){
    input();
    dp(n);
    int res=0;
    for(int i=1; i<=n; i++)
        res=max(res,iMem[i]);
    cout <<res;
}
