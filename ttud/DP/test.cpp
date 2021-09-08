#include<bits/stdc++.h>
using namespace std;
int x[26];
bool visited[26];

int* findNext(int k){
    int *next;
    next = new int[4];
    next[0] = k+1;
    next[1] = k-1;
    next[2] = k-5;
    next[3] = k+5;
    if(k<=5){
        next[2] = -1;
    }
    if(k%5==0){
        next[0] = -1;
    }
    if(k>=21){
        next[3] = -1;
    }
    if((k+4)%5==0){
        next[1] = -1;
    }
    return next;
}

bool check(int v, int k){
    if(v!=-1){
        if(!visited[v])
            return true;
    }
    return false;
}

void solution(){
    cout << "Path: ";
    for(int i=1; i<=24; i++)
        cout << x[i] << "->";
    cout << endl;
}

void Try(int k){
    int* next;
    next = findNext(x[k-1]);
    for(int i=0; i<4; i++){
        int v = next[i];
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;
            if(k==24) solution();
            else Try(k+1);
            visited[v] = false;
        }
    }
}

main(){
    memset(visited,false, sizeof(visited));
    visited[6] = true;
    visited[1] = true;
    x[1] = 1;
    Try(2);
    cout << "----------------------";
}
