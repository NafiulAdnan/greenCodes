#include<bits/stdc++.h>

using namespace std;
int d[120][120];

void floyd_warshal(int n)
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
//                    cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
                    d[i][j]= d[i][k]+ d[k][j];
                }
            }
        }
    }


}

void init(int n)
{

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            if(i==j)d[i][j]=0;
        else
            d[i][j]=123456;
    }

}
int ans(int n)
{
    int a,b;
    scanf("%d%d",&a,&b);

    int mx=0;

    for(int i=0; i<n; i++)
    {
//        cout<<d[a][i]<<" = "<<d[i][b]<<endl;

     //   if(d[a][i]!=123456 && d[i][b]!=123456)

            mx = max(mx, d[a][i]+d[i][b]);
    }
    return max(mx,d[a][b]);
}

int main()
{
    int t,cs=1;

    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int a,b;

        init(n);

        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            //  a++,b++;
            d[a][b]=1;
            d[b][a]=1;
        }

        floyd_warshal(n);
        printf("Case %d: %d\n",cs++,ans(n));
    }
}
