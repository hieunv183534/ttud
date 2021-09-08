#include<bits/stdc++.h>

using namespace std;

int x[1000];
int a[1000];
int cnt=0;
int T=0;
int M,N;

bool check(int v, int k){
    if(k<N) return true;
    return (T + a[k]*v == M);
}

void solution(){
    if(x[1]+x[2]==6){
        cnt++;
    }

}

void Try(int k){
    for(int v=1; v<=M-T; v++){
        if(check(v,k)){
            x[k] = v;
            T+=a[k]*v;
            if(k==N) solution();
            else Try(k+1);
            T-= a[k]*v;
        }
    }
}


main(){
    cin >> N >> M;
    for(int i =1; i<=N; i++){
        cin >> a[i];
    }
    Try(1);
    cout << cnt;
}
