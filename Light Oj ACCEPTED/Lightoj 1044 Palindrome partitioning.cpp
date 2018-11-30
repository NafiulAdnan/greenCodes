#include<bits/stdc++.h>
using namespace std;

int pal[1005][1005];
int dp[1005];
string s;
int ispal(int i,int j)
{
    if(i==j || i>j)return 1;

    int &ret = pal[i][j];

    if(ret==-1)
    {
        if(s[i]==s[j])
        {
          //  cout<<i<<" "<<j<<endl;
            ret = ispal(i+1,j-1);
        }
        else ret = 0;
    }
    return ret;

}

int rec(int i)
{
    if(i==s.size())return 0;
    if(i==s.size()-1)return 1;

    int &ret = dp[i];
    if(ret==-1)
    {
        ret = 1005;
        for(int j=i+1; j<s.size(); j++)
        {
            if(ispal(i,j))ret = min( ret,  1+rec(j+1));
          ///  cout<<i<<" "<<j<<" "<<ispal(i,j)<<endl;
        }
        ret = min(ret,1 + rec(i+1));
    }

    return ret;


}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        memset(pal,-1,sizeof(pal));
        cin>>s;

      //  cout<<ispal(4,7)<<endl;

        int ans =rec(0);

        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
}
