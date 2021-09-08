#include<bits/stdc++.h>

using namespace std;
int n,m;
int x[100];
int c[444][3];
bool visited[100];
int f,f_min;

vector<int> d;

void input()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
        //if(c[i][1]==1) d.push_back(c[i][0]);
    }
}

int check(int v, int k)
{
    if(!visited[v])
    {
        for(int i=1; i<=m; i++)
        {
            if(x[k-1]==c[i][0]&&c[i][1]==v) return c[i][2];
        }
    }
    return 0;
}

void updateBest()
{
    for(int i=1; i<=m; i++)
    {
        if(c[i][0]==x[n]&&c[i][1]==1)
        {
            if((f+c[i][2])<f_min) f_min = f+c[i][2];
        }
    }
}

/*
bool nhanhCan(int k)
{
    int cnt=0;
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<d.size(); j++)
        {
            if(x[i]==d[j]) cnt++;
        }
    }
    if(cnt<d.size()) return true;
    else return false;
}
*/

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if(check(v,k))
        {
            x[k]=v;
            f=f+check(v,k);
            visited[v] = true;
            if(k==n)
            {
                updateBest();
            }
            else
            {
                // if(nhanhCan(k))
                Try(k+1);
            }
            visited[v]= false;
            f=f-check(v,k);
        }
    }
}

int main()
{
    f_min = LONG_MAX;
    f=0;
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
    }
    visited[1]= true;
    x[1]=1;
    input();
    Try(2);
    cout << f_min;


    return 0;
}
