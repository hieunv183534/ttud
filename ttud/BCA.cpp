#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define NMAX 100

vector<int> G[NMAX];

int m,n,conflict[NMAX][NMAX],x[NMAX],load[NMAX],best;

void enter(){ //doc du lieu
    int k,x,y;
    cin>>m>>n;
    for(int i=1 ; i<=m ; i++)
    {
        cin>>k;
        for(int j=1 ; j<=k ; j++)
        {
            cin>>x;
            G[x].push_back(i); // them giao vien i vao danh sach day mon x
        }
    }
    cin>>k;
    for(int i=1 ; i<=k ; i++)
    {
        cin>>x>>y;
        conflict[x][y]=1;
        conflict[y][x]=1;
    }
}

int check(int v,int i)
{
    for(int j=1 ; j<i ; j++)
    {
        if (conflict[i][j])
            if (x[j] == v) return 0; //kiem tra giao vien cua x[j]
    }
    return 1;
}

void updateBest()
{
    int local_max = load[1];
    for(int i=2 ; i<=m ; i++)
        local_max = max(local_max,load[i]);
    best = min(best, local_max);
}

void Try(int i)
{
    for(int j=0 ; j<(int)G[i].size() ; j++)
    {
        int v = G[i][j];
        if (check(v,i))
        {
            x[i] = v; //gan giao vien v cho mon i
            load[v]++; //tang so luong mon cua giao vien v

            if (i==n) updateBest();
            else
                if (load[v]<best) Try(i+1);
            load[v]--; //giam so luong mon cua giao vien v
        }
    }
}


main(){
    freopen("a.inp","r",stdin);
    enter();
    best = LONG_MAX;
    Try(1);
    cout<<best;
}
