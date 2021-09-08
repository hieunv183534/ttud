#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i< n ; i++)
    {
        scanf("%d",&a[i]);
    }
    int maxsum = -9999999;
    for(int i=0; i< n; i++)
    {
        for (int j=i; j < n; j++)
        {
            int tmpsum=0;
            for(int k=i; k<=j; k++)
            {
                tmpsum+=a[k];
            }
            if(tmpsum>maxsum) maxsum = tmpsum;
        }
    }
    printf("%d",maxsum);
    return 0;
}
