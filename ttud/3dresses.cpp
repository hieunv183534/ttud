#include<bits/stdc++.h>

using namespace std;
const int N=100;
int n,m;
int best;
int f;
int c[N]; // giá bán
int cap[N][N]; // cặp
bool visited[N];
int x[N];

void input()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> c[i];
    }
    int a,b;
    for(int i=1; i<=m; i++)
    {
        cin >> a >> b;
        cap[a][b] = 1;
        cap[b][a] = 1;
    }
}

bool check(int v, int k)
{
    if(!visited[v])
    {
        if(k==1)
        {
            return true;
        }
        else if(k==2)
        {
            if(cap[x[1]][v]) return true;
            else return false;
        }
        else if(k==3)
        {
            if((cap[x[1]][v])&&(cap[x[2]][v])) return true;
            else return false;
        }
    }
    return false;
}

void updateBest()
{
    best = min(best,f);
}

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if(check(v,k))
        {
            x[k]=v;
            f=f+c[v];
            visited[v] = true;
            if(k==3) updateBest();
            else
            {
                if(f<best)
                    Try(k+1);
            }
            f=f-c[v];
            visited[v] = false;
        }
    }
}

int main()
{
    best = 1e9;
    f=0;
    input();
    for(int i=1; i<=n; i++)
        visited[i] = false;
    Try(1);
    cout << best;

    return 0;
}
