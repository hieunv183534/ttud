#include<bits/stdc++.h>

using namespace std;
const int N=100;
int m,n;
int conflict[N][N];
vector<int> g[N];// lưu ds gv có thể cho môn i
int load[N]; // lưu số môn của gv j
int x[N]; // gán gv cho môn i
int best;

void input()
{
    int k,tmp;
    cin >> m >> n;
    for(int i=1; i<=m; i++)
    {
        cin >> k;
        for(int j=1; j<=k; j++)
        {
            cin >> tmp;
            g[tmp].push_back(i);
        }
    }
    cin >> k;
    int i,j;
    for(int a=1; a<=k ; a++)
    {
        cin >> i >> j;
        conflict[i][j] = 1;
        conflict[j][i] = 1;
    }

}

bool check(int v,int k)
{
    for(int j=1 ; j<k ; j++)
    {
        if (conflict[k][j])
            if (x[j] == v) return false; //kiem tra giao vien cua x[j]
    }
    return true;
}
void updateBest()
{
    int maxtmp = load[1];
    for(int i=2; i<=m; i++)
    {
        maxtmp = max(maxtmp,load[i]);
    }
    if(maxtmp<best) best = maxtmp;
}

//môn thứ k
void Try(int k)
{
    for(int i=0; i<=g[k].size(); i++)
    {
        int v=g[k][i];
        if(check(v,k))
        {
            x[k]=v;
            load[v]++;
            if(k==n) updateBest();
            else
            {
                if(load[v]<best)
                    Try(k+1);
            }
            load[v]--;
        }
    }
}

int main()
{
    input();
    best = 100;
    Try(1);
    cout << best;
    return 0;
}
