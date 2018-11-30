#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define LCM(a,b) (a / __gcd(a,b) ) * b
#define gcd(a,b) __gcd(a,b)
#define ll long long
ll dp[100005];
int main()
{
    FastRead;

    int t,cs=1,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(dp,0,sizeof(dp));

        dp[0]=1;
        ll a, sum =0, ans = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            sum = (sum + a)%m;
            ans += dp[sum];
            dp[sum]++;
        }

        cout<<"Case "<<cs++<<": "<<ans<<endl;

    }
}
