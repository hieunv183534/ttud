#include<bits/stdc++.h>

using namespace std;

int n;
int a[1000];

void Try(int k)
{
    for(int i=0; i<=1; i++)
    {
        a[k]=i;
        if(k==n)
        {
            for(int j=0; j<n; j++) cout << a[j];
            cout << endl;
        }
        else Try(k+1);
    }
}

int main()
{

    cin >> n;
    Try(0);


    return 0;
}
