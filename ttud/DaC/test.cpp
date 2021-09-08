#include<bits/stdc++.h>
using namespace std;

double distance(int a[], int b[]){
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

main(){
    int a[2] = {0,0};
    int b[2] = {3,4};
    cout << distance(a,b);
}
