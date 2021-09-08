#include<bits/stdc++.h>

using namespace std;
const int N=10001;
int n;
int a[N];
int best;
vector<int> g;
bool visited[N];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {

        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        for(int i=1; i<=n; i++)
            visited[i] = false;
        best =0;

        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                g.push_back(a[i]);
                for(int j=i+1; j<=n; j++)
                {
                    if(a[j]==(g.back()+1))
                    {
                        g.push_back(a[j]);
                        visited[j]=true;
                    }
                }
                best = max(best,(int)g.size());
                g.clear();
            }
        }
        cout << best ;
    }
    return 0;
}
