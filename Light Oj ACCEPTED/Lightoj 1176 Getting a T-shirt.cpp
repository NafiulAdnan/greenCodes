///Using MaxFlow Dinitz
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

map<string, int>cod;
int main()
{
    FastRead;

    cod["XXL"] = 6;
    cod["XL"]  = 1;
    cod["L"]   = 2;
    cod["M"]   = 3;
    cod["S"]   = 4;
    cod["XS"] = 5;

    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>m>>n;
        string s,d;
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
