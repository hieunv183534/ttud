#include<bits/stdc++.h>

using namespace std;
const int N=100;
int n;
int c[N][N];
int x[N];
int d, d_min;
bool visited[N];
int cm;

void input()
{
    cm=1e8;
    cin >> n;
    for(int i=0; i<=2*n; i++)
    {
        for(int j=0; j<=2*n; j++)
        {
            cin >> c[i][j];
            if(i!=j)
            {
                cm= min(cm,c[i][j]);
            }
        }
    }
}

bool check(int v, int k)
{
    return(!visited[v]);
}

void updateBest()
{
    if(d+c[x[n]+n][0]<d_min)
    {
        d_min = d+c[x[n]+n][0];
    }
}

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if(check(v,k))
        {
            x[k] = v;
            d = d + c[x[k-1]+n][x[k]]+c[x[k]][x[k]+n];
            visited[v] = true;
            if(k==n)
            {
                int g = d+ cm*(2*(n-k)+1);
                if(g<d_min)
                {
                    updateBest();
                }
            }
            else
            {
                Try(k+1);
            }
            visited[v] = false;
            d = d - c[x[k-1]+n][x[k]]-c[x[k]][x[k]+n];
        }
    }
}

int main()
{
    input();
    for(int i=1; i<=n; i++)
        visited[i] = false;
    d=0;
    d_min = 1e9;
    x[0]=-n;
    Try(1);
    cout << d_min << endl;
    return 0;
}
