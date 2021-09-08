#include<bits/stdc++.h>
using namespace std;
const int N = 50001;
int a[N][2];
int n;

double distance(int a[], int b[]){
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

pair<int,int> maxMid(int l, int r , int mid){
    pair<int,int> maxPair =  make_pair(mid,mid+1);
    double mx = distance(a[mid],a[mid+1]);
    for(int i=mid; i>=l; i--){
        for(int j=mid+1; j<=r; j++){
            if(distance(a[i],a[j])>mx){
                maxPair.first = i;
                maxPair.second = j;
                mx = distance(a[i],a[j]);
            }
        }
    }
    return maxPair;
}

pair<int,int> solve(int l, int r){
    if(l==r) return make_pair(-1,-1);
    int mid = (l+r)/2 ;
    pair<int,int> wL = solve(l,mid);
    pair<int,int> wR = solve(mid+1,r);
    pair<int,int> wM = maxMid(l,r,mid);
    double dis_wL = distance(a[wL.first],a[wL.second]);
    //cout << "dis_wl = " << dis_wL << endl;
    double dis_wR = distance(a[wR.first],a[wR.second]);
    //cout << "dis_wr = " << dis_wR << endl;
    double dis_wM = distance(a[wM.first],a[wM.second]);
    //cout << "dis_wm = " << dis_wM << endl;
    if(dis_wL>dis_wR){
        if(dis_wL>dis_wM) return wL;
        else return wM;
    }
    else{
        if(dis_wR>dis_wM) return wR;
        else return wM;
    }
}

main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    pair<int,int> p = solve(0,n-1);
    cout << p.first << " " << p.second << " " << distance(a[p.second],a[p.second]);
    //cout << "\n" << distance();
}
