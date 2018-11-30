#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define LCM(a,b) (a / __gcd(a,b) ) * b
#define gcd(a,b) __gcd(a,b)
#define ll long long

ll k;
string toString(ll n)
{
    string ts="";
    while(n!=0)
    {
        ts += (n%10 + '0');
        n/=10;
    }
    reverse(ts.begin(),ts.end());
    return ts;
}

string target;
ll a,b,n;
ll dp[12][2][100][100];

ll possible(int pos, int isTop, int modSum,int modNum)
{
    if(pos==target.size())
    {
        return modNum + modSum == 0?1:0;
    }
    ll &ret  = dp[pos][isTop][modSum][modNum];
    if(ret==-1)
    {
        ret = 0;
        int maxNum = isTop? (target[pos]-'0'): 9;

        for(int i=0; i<=maxNum; i++)
        {
            ret += possible(pos+1, isTop && i==maxNum, (modSum+i)%k, (((modNum*10)%k)+i)%k);
        }
    }
    return ret;
}


int main()
{
    FastRead;

    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        cout<<"Case "<<cs++<<": ";

        if(k>99)
        {
            cout<<0<<endl;
            continue;
        }


        memset(dp,-1,sizeof(dp));
        target = toString(b);
        ll high = possible(0,1,0,0);


        memset(dp,-1,sizeof(dp));
        target = toString(a-1);
        ll low = possible(0,1,0,0);


        cout<<high-low<<endl;
    }



}
