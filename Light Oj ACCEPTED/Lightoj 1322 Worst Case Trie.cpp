#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll mod =10000;
ll put[10005];
int main()
{
    int t,cs=1,n;
    ll a,lsta = 2;
    put[1]=2;
    put[0]=1;

    for(int i=2; i<=10000; i++)
    {
        a = lsta *(i) +1;
        a%=mod;
        lsta=a;
        put[i]=a;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll rem = n%10000,tk;
        if(n>5)
            printf("Case %d: %.4hd\n",cs++, put[rem]);
        else  printf("Case %d: %hd\n",cs++, put[rem]);
    }
}
