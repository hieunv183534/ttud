#include<bits/stdc++.h>

using namespace std;

int n;
int X[1001];
int Y[1001];
int f;
int f_min;
int T;
int y[1001];
bool visited[1001];

int XY( int y[])
{
    int sum =0;
    for(int i=1; i<=n ; i++)
    {
        sum+= X[i]*y[i];
    }
    return sum;
}

bool check(int v, int k)
{
    return !visited[v];
}

void updateBest()
{
    int tmp = XY(y);
    if(tmp<f_min) f_min = tmp;
}

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if(check(v,k))
        {
            y[k]= Y[v];
            visited[v] = true;
            if(k==n) updateBest();
            else
            {
                Try(k+1);
            }
            visited[v] = false;
        }
    }
}

int main()
{
      cin >> T;
    for(int i=1; i<=T; i++)
    {

        {
            cin >> n;
            for(int j=1; j<=n; j++) cin >> X[j];
            for(int j=1; j<=n; j++) cin >> Y[j];
            f_min=1e9;
            Try(1);
        }

        cout << "Case #" << i<< ": " << f_min << endl;
    }
    return 0;
}
