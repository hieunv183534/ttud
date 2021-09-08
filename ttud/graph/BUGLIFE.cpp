#include<bits/stdc++.h>
using namespace std;
const int N = 2345;;
int n,m;
vector<int> A[N];
queue<int> Q;
int num[N];
int res;
int T;


void bfs(int s)
{
    num[s] = 1;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << "|"<< res<<"|" << endl;
        for(int i=0; i<A[u].size(); i++)
        {
            int v = A[u][i];
            if(num[v]==-1)
            {
                Q.push(v);
                num[v] = 3-num[u];
            }
            else
            {
                if((3-num[u])!=num[v])
                {
                    res = 0;
                    break;
                }
            }
        }
        if(res==0) break;
    }
}

void solve()
{
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        int u,v;
        //memset(num,-1,sizeof(num));
        for(int i=1; i<=2000; i++){
            A[i].clear();
            num[i]=-1;
        }

        cin>>n>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>u>>v;
            A[u].push_back(v);
            A[v].push_back(u);
        }

        for(int s=1; s<=n; s++)
        {
            res =1; cout <<".."<<res<< endl;
            if(num[s]==-1)
                bfs(s);
            if(res==0){
                    cout << "*****" << endl;
                break;
            }

        }
        cout << "Scenario #"<<i<<": "<< res <<endl;
        if(res==1)
            cout <<"No suspicious bugs found!"<<endl;
        else
            cout <<"Suspicious bugs found!"<<endl;

    }
}

main()
{
    solve();
}
