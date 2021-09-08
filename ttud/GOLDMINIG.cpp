#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+1;
int n,k1,k2;
int a[N];
int x[N];
int f, f_max, cnt;

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

inline void input(){
    read(n), read(k1), read(k2);
    for(int i=1; i<=n; i++)
        read(a[i]);
}

void updateBest(){
    if(f>f_max) f_max = f;
}

void Try(int k){
    for(int v=x[k-1]+k1; v<=x[k-1]+k2; v++){
        x[k] = v;
        f = f+a[v];
        if(x[k]+k1>n) updateBest();
        else Try(k+1);
        f = f-a[v];
    }
}

main(){
    input();
    memset(x,0,sizeof(x));
    x[0] = 1-k1;
    f_max = 0;
    f = 0;
    Try(1);
    cout << f_max;
}
