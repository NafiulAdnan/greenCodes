#include<bits/stdc++.h>

using namespace std;

#define ll long long
//ll dp[100000001];
//ll calc(ll n)
//{
//    if(n==1)return n;
//  //  if(dp[n]!=-1)return dp[n];
//
//    return n * (n-1) +
//}
//short int dp[100000001];
ll mod =10000;
ll put[10005];
int main()
{
    int t,cs=1,n;
    ll a,i;


//    dp[1]=2;
//    dp[2]=5;
//    dp[0]=1;
//    for(i=3; i<=100000000; i++)
//
//    {
//        ll a = i* dp[i-1]  + 1;
//        dp[i] = a%mod;
//    }
put[0]=1;


    ll lsta = 2,lstb = 5;
    a=2;
    i=0;
    put[1]=2;
    for(int i=2; i<=10000; i++)
    {
        ///     for(int j=i*10000 +1; j <= (i+1)*10000 ; j++ )
        {
            a = lsta *(i) +1;
//           if(i*10000 +j == 567)cout<<" df "<<a%mod<<endl;
           a%=mod;
            lsta=a;

            put[i]=a;
        }
    }
//   cout<<a<<endl;



    scanf("%d",&t);
    //memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%d",&n);

//        int pos = n/10000;
//        ll got = put[pos];

        ll rem = n%10000,tk;

//        for(int i=1; i<rem; i++)
//        {
//            tk = got * (pos * 10000 +i+1) + 1;
//
//
//            tk %= mod;
//            got = tk;
//        }

       // cout<<put[rem]<<endl;


        if(n>5)

            printf("Case %d: %.4hd\n",cs++, put[rem]);
              else  printf("Case %d: %hd\n",cs++, put[rem]);


    }





//    for(i=3; i<=100000000; i++)
//
//    {
//        ll a = i* dp[i-1]  + 1;
//        dp[i] = a%mod;
//    }


}
//    scanf("%d",&t);
//    //memset(dp,-1,sizeof(dp));
//    while(t--)
//    {
//        scanf("%d",&n);
//        //  n--;
//
//        if(n>=5)
//
//            printf("Case %d: %.4hd\n",cs++, dp[n]);
//        else         printf("Case %d: %hd\n",cs++, dp[n]);
