///Using MaxFlow Dinitz

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define MOD              1000000007
#define fast_cin         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define UNIQUE(v)        (v).erase(unique((v).begin(),(v).end()),(v).end())
#define POPCOUNT         __builtin_popcountll
#define RIGHTMOST        __builtin_ctzll
#define LEFTMOST(x)      (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y)    (((vlong)(log10((x))/log10((y))))+1)
#define NORM(x)          if(x>=mod) x-=mod;if(x<0) x+=mod;
#define ODD(x)           (((x)&1)==0?(0):(1))
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define D(x)             cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define DD(x,y)          cerr << __LINE__ << ": " << #x << " = " << x << "   " << #y << " = " << y << '\n'
#define DDD(x,y,z)       cerr << __LINE__ << ": " << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << '\n'
#define DBG              cerr << __LINE__ << ": Hi" << '\n'

using namespace std;

//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

///Max Flow Dinitz (Zobayer Vhai)
///clear()
///Build graph by addEdge
///Call findFLOW() to find maximum flow

const int INF = 1<<28; ///INT_MAX
const int MAXN = 60, MAXE=400;
///Maximum number of nodes and edges.

int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], nxt[MAXE], to[MAXE];

struct DINITZ
{
    int src, snk, nNode, nEdge;

    ///Parameters: (source, sink, no of nodes)
    void clear(int _src, int _snk, int _n)
    {
        src = _src, snk = _snk;
        nNode = _n, nEdge = 0;
        memset(fin,-1, sizeof fin);
    }

    ///Parameters: (from, to, capacity)
    void addEdge(int u, int v, int _cap)
    {
        to[nEdge] = v, cap[nEdge] = _cap, flow[nEdge] = 0;
        nxt[nEdge] = fin[u];
        fin[u] = nEdge++;
        ///Make this 2nd capacity zero for directed edge
        _cap=0;
        to[nEdge] = u, cap[nEdge] = _cap, flow[nEdge] = 0;
        nxt[nEdge] = fin[v];
        fin[v] = nEdge++;
    }

    bool BFS()
    {
        int st, en;
        memset(dist,-1,sizeof dist);
        dist[src] = st = en = 0;
        Q[en++] = src;
        while(st<en)
        {
            int u = Q[st++];
            for(int i = fin[u]; i>=0; i = nxt[i])
            {
                int v = to[i];
                if(flow[i] < cap[i] && dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    Q[en++] = v;
                }
            }
        }
        return dist[snk] != -1;
    }

    int DFS(int u, int fw)
    {
        if(u == snk) return fw;
        for(int &e = pro[u]; e >= 0; e = nxt[e])
        {
            int v = to[e];
            if(flow[e] < cap[e] && dist[v] == dist[u] + 1)
            {
                int cur_flow = DFS(v, min(cap[e]-flow[e], fw));
                if(cur_flow > 0)
                {
                    flow[e] += cur_flow;
                    flow[e^1]-= cur_flow;
                    return cur_flow;
                }
            }
        }
        return 0;
    }

    long long findFLOW()
    {
        long long fflow = 0;
        while(BFS())
        {
            for(int i = 0; i<= nNode; i++)
            {
                pro[i] = fin[i];
            }
            while(true)
            {
                long long fw=DFS(src,INF);
                if(fw > 0)
                    fflow += fw;
                else
                    break;
            }
        }
        return fflow;
    }
} dinitz;


int A[MAXN],B[MAXN];

int grid[MAXN][MAXN];

#define Fastread ios_base::sync_with_stdio(false);cin.tie(NULL);
map<string, int>cod;
int main()
{
    Fastread;

    cod["XXL"] = 6;
    cod["XL"]  = 1;
    cod["L"]   = 2;
    cod["M"]   = 3;
    cod["S"]   = 4;
    cod["XS"] = 5;

    int t,cs=1;
    cin>>t;
    //  scanf("%d",&t);
    while(t--)
    {

        int n,m;
        cin>>m>>n;
        string s,d;
        //   sff(n,m);
        int source = 0;
        int sink = n+8;
        dinitz.clear(source,sink,sink+1);
        for(int i=1; i<=6; i++)
        {
            dinitz.addEdge(source,i,m);
        }

        for(int i=1; i<=n; i++)
        {
            cin>>s>>d;
            dinitz.addEdge(cod[s],6+i,1);
            dinitz.addEdge(cod[d],6+i,1);
            dinitz.addEdge(6+i, sink, 1);

        }
        cout<<"Case "<<cs++<<": ";

        int ans= dinitz.findFLOW();
        if(ans==n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }


}
