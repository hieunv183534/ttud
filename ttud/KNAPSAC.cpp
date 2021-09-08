#include<bits/stdc++.h>

using namespace std;
int n,B;
int a[40][2];
bool visited[40];
int x[40];
int b,c;
int best;

bool check(int v, int k)
{
    return (!visited[v]);
}

void updateBest(int k)
{
    if(b>B)
    {
        int temp = c-a[x[k]][1];
        best = max(best,temp);
    }
    else
    {
        best = max(best,c);
    }
}

void Try(int k)
{
    for(int v=0; v<=n; v++)
    {
        if(check(v,k))
        {
            x[k] = v;
            b=b+a[v][0];
            c=c+a[v][1];
            visited[v] = true;
            if((b>=B)||(k==n)) updateBest(k);
            else
            {
                Try(k+1);
            }
            b=b-a[v][0];
            c=c-a[v][1];
            visited[v] = false;
        }
    }
}

int main()
{
    cin >> n >> B;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
    }

    b=0,c=0;
    best=0;
    Try(1);
    cout << best;
    return 0;
}
