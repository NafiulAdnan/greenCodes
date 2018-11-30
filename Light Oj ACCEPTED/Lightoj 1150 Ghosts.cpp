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

vector<int>v[MAX];
ll n,m,q,a,b,c,sum=0,cnt=0;
//ll arr[1000055];
map<ll,bool>mp;
string s;

int match[MAX];
bool  col[MAX];
bool done[30][30];
char grd[30][30];
int dist[55][55];
vector<pair<int,int> > g,h;
map< pair<int,int >,int > itis;
int TD[50][50];
#define MP make_pair
int x[]= {1,-1,0,0};
int y[]= {0,0,1,-1};

void bfs(int nd)
{
    queue< pair<int, int > >q;
    mem(done);
    mem(TD);

    q.push(MP(g[nd].first, g[nd].second));
    int d = 1;

    done[g[nd].first][g[nd].second]=1;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();


        for0(i,4)
        {
            int xi = r + x[i];
            int yi = c + y[i];

            if(xi >=0 && xi<n && yi >=0 && yi<n && grd[xi][yi]!='#' )
            {
                if(!done[xi][yi])
                {
                    q.push(MP(xi,yi));
                    done[xi][yi]=1;

                    TD[xi][yi] = TD[r][c] +2;

                    if(grd[xi][yi]=='H')
                    {
//                        cout<<nd<<"=  "<<xi<<", "<<yi<<" "<< TD[xi][yi]<<" "<<itis[MP(xi,yi)]<<" th"<<endl;
                        dist[nd][itis[MP(xi,yi)]] = TD[xi][yi];
                    }
                }
            }
        }
    }
    return;


}



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

int BPM()
{
    memset(match,-1,sizeof(match));
    int cnt = 0;

    for0(i,g.size())
    {
        mem(col);
        //  col[i]=1;
        if(dfs(i))cnt++;
    }
    return cnt;
}


int arr[102],brr[102];
int main()
{
    FastRead;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        mem(col);
        cin>>n;
        for0(i,n)cin>>grd[i];


        memset(dist, -1,sizeof(dist));

        for0(i,n)
        {
            for0(j,n)
            {
                if(grd[i][j]=='G')
                {
                    g.pb(make_pair(i,j));
                }
                else if(grd[i][j]=='H')
                {
                    h.pb(make_pair(i,j));
                    itis[MP(i,j)] = h.size()-1;
                }
            }
        }

        for0(i,g.size())
        {
            bfs(i);
        }

        int low = 2, high = 50000;
        int mini = 50000;

        while(low<=high)
        {
            int mid = low + high;
            mid/=2;

            for0(i,g.size())
            {
//                cout<<"For "<<i <<" :";
                for0(j,h.size())
                {
                    if(dist[i][j]!=-1 && dist[i][j]<=mid)
                    {
//                        cout<<dist[i][j]<<" ["<<j<<"] ";
                        v[i].pb(j);
                    }
                }
//                cout<<endl;
            }
            int ans = BPM();

//            cout<<mid<<" "<<ans<<endl;

            if(ans==h.size())
            {
                mini = min(mini, mid);
                high = mid-1;
            }
            else low = mid+1;


            for0(x,g.size())
            {
                v[x].clear();
            }

        }



        cout<<"Case "<<cs++<<": ";

        if(mini==50000)cout<<"Vuter Dol Kupokat"<<endl;
        else cout<<mini+2<<endl;

        g.clear();
        h.clear();




    }


}




