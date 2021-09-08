#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, k1,k2;
int cnt, a;

bool check(int v, int k){
    if(k==1){
        return true;
    }else{
        if(v==1){
            if(a==k2) return false;
            else return true;
        }else{
            if(a<k1) return false;
            else return true;
        }
    }
}

void solution(){
    if(a==0 || a>=k1){
        cnt++;
    }
}

void Try(int k){
    for(int v=0; v<=1; ++v){
        if(check(v,k)){
            int lu = a;
            if(v==0) a=0;
            if(v==1) a++;
            if(k==n) solution();
            else Try(k+1);
            a=lu;
        }
    }
}

main(){
    cin >> n >> k1 >> k2;
    a=0;
    cnt=0;
    Try(1);
    cout << cnt;
}
