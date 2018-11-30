#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mem(n) memset(n,0,sizeof(n))
#define LCM(a,b) (a / __gcd(a,b) ) * b
#define gcd(a,b) __gcd(a,b)
#define for0(l,n) for(int l=0;l<n;l++)
#define for1(l,n) for(int l=1;l<=n;l++)
#define bug(n) cout<<">> "<<n<<" <<";
#define pb push_back
#define squerit(n) (ll)n*n
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)

bool vowel(char a)
{
    a= toupper(a);
    if((a=='A')||(a=='E')||(a=='I')||(a=='O')||(a=='U'))return 1;
    return 0;
}

ll n,m,q,a,b,c,sum=0,cnt=0;
ll arr[1000055];
map<ll,bool>mp;
string s;
int main()
{
//    cout<< (4^2);
    FastRead;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        ll x=0;

        vector<ll>v[50050];

        cin>>n>>m;

        for0(i,n)
        {
            for0(j,m)
            {
                cin>>a;

                v[i].pb(a);
            }
        }

        vector<ll>tv;

        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
//                cout<<"   i and j "<<i<<" "<<j<<endl;
                if( (n-i-1) % 2==0 )
                {
                    if((m-j-1)%2==1)
                    {
//                        cout<<i<<", "<<j<<endl;

                        tv.pb(v[i][j]);
                    }
                }
                else if( (n-i-1) % 2==1 )
                {
                    if((m-j-1)%2==0)
                    {
//                        cout<<i<<", "<<j<<endl;

                        tv.pb(v[i][j]);
                    }
                }
            }
        }
//        cout<<" adf"<<endl;
        if(tv.size())
            x= tv[0];
            if(tv.size()>1)
        for1(i,tv.size()-1)x = x^tv[i];

//        cout<<x<<endl;

        if(x==0)cout<<"Case "<<cs++<<": lose"<<endl;
        else cout<<"Case "<<cs++<<": win"<<endl;

    }


}

















