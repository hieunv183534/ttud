#include<bits/stdc++.h>

using namespace std;
int n;
int c[100][100];
int f;
int f_min;
int x[100];
bool visited[100];
int cm;

void input()
{
    cm =1e9;
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin >> c[i][j];
            if(i!=j&&c[i][j]<cm) cm= c[i][j];
        }
}

void updateBest()
{
    if(f+c[x[n]][x[1]]<f_min)
    {
        f_min = f+c[x[n]][x[1]];
    }
}


bool check(int v, int k)
{
    return !visited[v];
}

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if(check(v,k))
        {
            x[k] = v;
            f= f+c[x[k-1]][x[k]];
            visited[v] = true;
            if(k==n) updateBest();
            else
            {
                int g =f+cm*(n-k+1);
                if(g<f_min)
                    Try(k+1);
            }
            f= f-c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }

}


int main()
{
    input();
    for(int v=1; v<=n; v++)
    {
        visited[v] = false;
    }
    visited[1] = true;
    x[1] = 1;
    f=0;
    f_min = 1e9;
    Try(2);
    cout << f_min << endl;
    return 0;
}
