#include<bits/stdc++.h>
using namespace std;
int dp[105][105][105];
int arr[105];
int n;
int rec(int st,int nd,int pos)
{
    if(pos==n+1)
    {
        return 0;
//        if(st==0 && nd==n+1)return 0;
//        if(st==0 && nd!=n+1)return 1;
//        if(nd==n+1 && st!=0)return 1;
//
//        else if(st!=nd)return 2;
//        return 1;
    }

    int ret = dp[st][nd][pos];
    if(ret!=-1)return ret;
    ret = 0;

    if(arr[pos] >=arr[st])
    {
        if(arr[pos]<=arr[nd])
        {
            ret = max(ret,rec(pos,nd,pos+1)+1);
            ret = max(ret,rec(st,pos,pos+1)+1);
        }
    }
    ret = max(ret, rec(st,nd,pos+1));
    return dp[st][nd][pos]=ret;
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        arr[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        arr[n+1]=100005;
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,n+1,1);

        printf("Case %d: %d\n",cs++,ans);
    }
}
