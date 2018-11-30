/// AC

#include<bits/stdc++.h>
using namespace std;

int dp[50][10][10];
char s[55];
bool vowel(char c)
{
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return 1;
    return false;
}

int solve(int id,int v,int c)
{
    if(v>=3 || c>=5 )return 1;
    if(id>=strlen(s))return 2;

    int &ret = dp[id][v][c];

    if(ret==-1)
    {
        if(vowel(s[id]))
        {
            ret = solve(id+1, v+1,0);
        }
        else if(s[id]=='?')
        {
            ret = solve(id+1,0,c+1)| solve(id+1,v+1,0);
        }
        else ret = solve(id+1,0,c+1);
    }
    return ret;

}
int main()
{
    int t,cs=1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",s);
        memset(dp,-1,sizeof(dp));

        int ans = solve(0,0,0);

        string x;

        if(ans==1)
        {
            x="BAD";
        }
        else if(ans==2)x="GOOD";
        else x= "MIXED";

        printf("Case %d: ",cs++);
        cout<<x<<endl;
    }
}

