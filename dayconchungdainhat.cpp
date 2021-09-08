#include<bits/stdc++.h>
using namespace std;
int X[1000]={ 1, 3, 4, 5, 7, 8, 9, 2, 4, 6 };
int Y[1000]={ 2, 3, 1, 5, 4, 6, 8, 7, 9, 4};
int iMem[1000][1000];


int LCS(int i, int j){
    if(i==0||j==0) return 0;
    if(iMem[i][j]!=-1) return iMem[i][j];
    int res=0;
    res=max(res,LCS(i,j-1));
    res=max(res,LCS(i-1,j));
    if(X[i]==Y[j]){
        res=max(res,1+LCS(i-1,j-1));
    }
    iMem[i][j]=res;
    return res;
}

main(){
     memset ( iMem , -1 , sizeof ( iMem ));

    cout << LCS(10,10);
}
