#include<bits/stdc++.h>

using namespace std;

int gapGhenh(int arr[] , int m ){
    int result = 1;
    int tmp = arr[1];

    for(int i= 2; i<= m ; i++){
        if(arr[i] != tmp ){
            result++;
            tmp = arr[i];
        }
    }

   return result;
}

int main(){
    int m;
    cin >> m;
    int arr[m+1];
    for(int i = 1; i <= m ; i++){
        cin >> arr[i];
    }
    int n;
    cin >> n;
    int fix[n][2];
    for(int i=0 ; i < n; i++){
        cin >> fix[i][0] >> fix[i][1] ;

        }

    int kq[n];
    for(int i=0 ; i<n ; i++){
        int a = fix[i][0];
        int b = fix[i][1];
        arr[a] = b;
        kq[i] = gapGhenh(arr, m);
    }

    for(int i =0; i< n; i++)
        cout << kq[i]<< endl;


    return 0;
}
