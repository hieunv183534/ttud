#include<bits/stdc++.h>
using namespace std;

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

main(){
    int* next;
    next = findNext(25);
    for(int i=0; i<4; i++)
        cout << next[i] << "   ";
}
