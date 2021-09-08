#include<bits/stdc++.h>

using namespace std;
const int n=7;
int x[10];                          // 1 2 3 4 5 6 7
int m;                              // I C T H U S K
bool visited[10];
int cnt;                           // ICT-K62+HUST = N

bool check(int v, int k)
{
    return (!visited[v]);
}

void updateBest()
{
    int ict = 100*x[1]+10*x[2]+x[3];
    int k62 = 100*x[7] +62;
    int hust = 1000*x[4]+100*x[5]+10*x[6]+x[3];
    int tmp = ict-k62+hust;
    if(tmp==m) cnt++;
}

void Try(int k)
{
    for(int v=1; v<=9; v++)
    {
        if(check(v,k))
        {
            x[k] = v;
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
    cin >> m;
    cnt =0;
    for(int i=1; i<=9; i++)
        visited[i] = false;
    if(m%2==0)
    {
        Try(1);
    }

    cout << cnt;

    return 0;
}
