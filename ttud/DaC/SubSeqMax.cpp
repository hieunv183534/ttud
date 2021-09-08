#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int a[N];
int n;
#define int long long

int maxLeft(int l , int r){
    int mx = -1e9;
    int s = 0;
    for(int k=r; k>=l ; k--){
        s+= a[k];
        if(s>mx)
            mx = s;
    }
    return mx;
}

int maxRight(int l , int r){
    int mx = -1e9;
    int s =0;
    for(int k=l; k<=r; k++){
        s+= a[k];
        if(s>mx)
            mx=s;
    }
    return mx;
}

int solve(int l , int r){
    if(l==r) return a[r];
    int mid  = (l+r)/2;
    int wL = solve(l,mid);
    int wR = solve(mid+1,r);
    int maxL = maxLeft(l,mid);
    int maxR = maxRight(mid+1,r);
    int wM = maxL+maxR;
    return max(max(wL,wR),wM);
}

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cout << solve(1,n);
}
