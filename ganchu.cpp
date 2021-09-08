#include<bits/stdc++.h>
using namespace std;

int x[1000];
bool visited[10];
int N;
int cnt;

bool check(int v, int k){
    return !visited[v];
}

void solution(){
    if(x[1]!=0 && x[3]!=0 && (
 1000000*x[1]+ 100000*x[2]+ 11000*x[3]+ 100*x[4]+50 == 1000000*x[3] + 100000*x[5]+10000*x[1]+1000*x[4]+100*x[6]+ 19 + 2681431
                              )) cnt++;
}

void Try(int k){
    for(int v=0; v<=9; v++){
        if(check(v,k)){
            x[k]=v;
            if(k==N) solution();
            else Try(k+1);
        }
    }
}

main(){
    cin >> N;
    Try(1);
    cout << cnt;
}
