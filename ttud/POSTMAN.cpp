#include<bits/stdc++.h>
using namespace std;
#define int long long



main()
{
    // nhap n va mang tong
    int n,k;
    cin >> n >> k;
    int arr[10000][2];
    int a[10000][2];
    int b[10000][2];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    int temp0,temp1;


    // tach mang thanh hai mang âm và dương
    int n1=0;
    int n2=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i][0]>0)
        {
            a[n1][0] = arr[i][0];
            a[n1][1] = arr[i][1];
            n1++;
        }
        else
        {
            b[n2][0] = abs(arr[i][0]);
            b[n2][1] = arr[i][1];
            n2++;
        }
    }

    // sắp xếp mảng dương
    for(int i=0; i<n1-1; i++)
    {
        for (int j=i+1; j<n1; j++)
        {
            if(a[i][0]>a[j][0])
            {
                temp0 = a[i][0];
                a[i][0] = a[j][0];
                a[j][0] =temp0;
                temp1 = a[i][1];
                a[i][1] = a[j][1];
                a[j][1] =temp1;
            }
        }
    }


    //sắp xếp mảng âm
    for(int i=0; i<n2-1; i++)
    {
        for (int j=i+1; j<n2; j++)
        {
            if(b[i][0]>b[j][0])
            {
                temp0 = b[i][0];
                b[i][0] = b[j][0];
                b[j][0] =temp0;
                temp1 = b[i][1];
                b[i][1] = b[j][1];
                b[j][1] =temp1;
            }
        }
    }

    int t1=n1-1;
    int t2=n2-1;
    int sum=0;


    // rải bên mảng dương
    while(t1>=0)
    {
        sum = sum + (a[t1][0])*2;
        int tm= k;
        while((tm-a[t1][1])>=0)
        {

            tm=tm-a[t1][1];
            t1--;
        }
        if(t1>=0)
        {
            a[t1][1] = a[t1][1]-tm;
        }
    }


    //rải bên mảng âm
    while(t2>=0)
    {
        sum = sum + (b[t2][0])*2;
        int tm= k;
        while((tm-b[t2][1])>=0)
        {

            tm=tm-b[t2][1];
            t2--;
        }
        if(t2>=0)
        {
            b[t2][1] = b[t2][1]-tm;
        }
    }

    cout << sum ;


}
