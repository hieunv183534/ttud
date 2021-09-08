#include<bits/stdc++.h>

using namespace std;
char a[]=" abcdefghijklmnopqrstuvwxyz";
int b[]= {1,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int demKt(string s)
{
    int dem=0;
    for(int i=0; i<s.length(); i++)
    {
        for(int j=0; j<27; j++)
        {
            if(s[i]==a[j]) dem+=b[j];
        }
    }
    return dem;
}

int main()
{
    int T;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        string s;
        cin.ignore();
        getline(cin,s);
        int dem = demKt(s);
        if(i!=0) dem++;
        cout << "Case #" << (i+1) << " : " << dem << endl;
    }


    return 0;
}
