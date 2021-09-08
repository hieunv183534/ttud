#include<bits/stdc++.h>

using namespace std;
vector<string> g;

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        g.push_back(s);
    }
    int x=0;
    for(int i=0; i<n; i++ )
    {
        if(g[i]=="X++"||g[i]=="++X")
            x++;
        else x--;
    }
    cout << x;
    return 0;
}
