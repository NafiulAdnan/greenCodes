#include<bits/stdc++.h>
using namespace std;
int dp[102][102];
int cum[102],n,arr[102];

int solve(int l,int r)
{
    if(l>r)return 0;
    int &ret = dp[l][r];

    if(ret==-1)
    {
        ret=-11111;
        for(int i=l; i<=r; i++)
        {
            ret = max(ret, cum[i]-cum[l-1] - solve(i+1,r) );
            ret = max(ret,cum[r]-cum[i-1] - solve(l, i-1));
        }
    }
    return ret;

}
int main()
{
    int t,cs=1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        memset(cum,0,sizeof(cum));

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
            cum[i]= cum[i-1]+arr[i];
        }
        memset(dp,-1,sizeof(dp));

        int ans = solve(1,n);
        printf("Case %d: %d\n",cs++, ans);
    }
}
