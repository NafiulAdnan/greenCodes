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
#define MAX 155
int n,m;
char grd[50][50];
vector<int>v[26*26];
bool col[26*26];
int match[26*26];

bool  dfs(int nd)
{
    int sz = v[nd].size();
    for0(i,sz)
    {
        int u = v[nd][i];
        if(!col[u])
        {
            col[u]=1;
            if(match[u]==-1 || dfs(match[u]))
            {
                match[u]=nd;
                return true;
            }
        }
    }
    return false;
}
int leftSize ;
 int done = 0;

int BPM()
{
    memset(match,-1,sizeof(match));
    int cnt = 0;

    for0(i,done)
    {
        if(v[i].size()==0)continue;
        mem(col);

        //  col[i]=1;
        if(dfs(i))
        {
//            cout<<" ok for "<<i<<endl;
            cnt++;
        }
    }
//    cout<<"Got "<<cnt<<endl;
    return cnt;
}

int mark[30][30];
int main()
{
    FastRead;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for0(i,n)cin>>grd[i];
         done = 0;
        for0(i,n)
        {
            for0(j,m)
            {
                if(grd[i][j]=='*')mark[i][j]=done++;
            }
        }
        leftSize = 0;

//        cout<<done<<endl;

        for0(i,n)
        {
            for0(j,m)
            {
                if( (i%2 == j%2)  && grd[i][j]=='*')
                {
                  //  cout<<i<<" "<<j<<endl;
                    int a = mark[i][j];
                    leftSize++;
                    if(grd[i+1][j]=='*')
                    {
                        v[a].pb(mark[i+1][j]);

                   //     cout<<"See "<<i<<" "<<j <<" added "<< i+1<<" "<<j<<endl;
                 //   cout<<mark[i+1][j]<<endl;;

                    }

                    if(grd[i-1][j]=='*')
                    {
                        v[a].pb(mark[i-1][j]);
//                        cout<<"See "<<i<<" "<<j <<" added "<< i-1<<" "<<j<<endl;
//                        cout<<mark[i-1][j]<<endl;;


                    }
                    if(grd[i][j+1]=='*')
                    {
                        v[a].pb(mark[i][j+1]);
//                        cout<<"See "<<i<<" "<<j <<" added "<< i<<" "<<j+1<<endl;
//
//                        cout<<mark[i][j+1]<<endl;;

                    }
                    if(grd[i][j-1]=='*')
                    {
                        v[a].pb(mark[i][j-1]);
//                        cout<<"See "<<i<<" "<<j <<" added "<< i<<" "<<j-1<<endl;
//                        cout<<mark[i][j-1]<<endl;;


                    }
                }
            }
        }
//        cout<<leftSize<<endl;

//        for0(i,done)
//        {
//            if(v[i].size()==0)continue;
////            cout<<i<<" : ";
//            for0(j,v[i].size())cout<<v[i][j]<<" ";
//            cout<<endl;
//        }
//        cout<<endl;

        cout<<"Case "<<cs++<<": "<<done-BPM()<<endl;
        for0(i,done)v[i].clear();
        mem(mark);

        for0(i,n)for0(j,m)grd[i][j]='o';
    }
}















