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
const int MAXN = 220, MAXE=210*210*2;
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
//        if(snk==1)
//            cout<<"from, to, cap "<<u<<" "<<v<<" "<<_cap<<endl;
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

struct ice
{
    ll x, y, have, can;
};
vector<ice>v;

 double distEuclid(int i,int j)
{
    return sqrt((v[i].x-v[j].x)*(v[i].x-v[j].x) + (v[i].y-v[j].y)*(v[i].y-v[j].y));
}
int main()
{




    FastRead;
    int t,cs=1;
    cin>>t;
    double mxD;
    int N;
    while(t--)
    {
        cin>>N>>mxD;
        ice tmp;
        tmp = {0,0,0,0};
        v.pb(tmp);
        int totalP = 0;
        for1(i,N)
        {
            cin>>tmp.x>>tmp.y>>tmp.have>>tmp.can;
            totalP+=tmp.have;
            v.pb(tmp);
        }
        vector<int>okayIce;

        for1(sink,N)
        {
            int source = 0;
         //   int edgeMake = (N+)*(N+1);
            dinitz.clear(0,sink,N*2+1);


            for1(i,N)
            {
                dinitz.addEdge(source,i, v[i].have);

                if(i!=sink)dinitz.addEdge(i,i+N,v[i].can);
                for(int j=i+1; j<=N; j++)
                {
                    if(distEuclid(i,j)<=mxD)
                    {
                        if(i!=sink)
                            dinitz.addEdge(i+N,j,INF);
                        if(j!=sink)
                        {
                            dinitz.addEdge(j+N,i,INF);
                        }
                    }
                }
            }

            int thisFlow = dinitz.findFLOW();

            if(thisFlow==totalP)
            {
                okayIce.pb(sink-1);
            }

        }


        cout<<"Case "<<cs++<<":";
        if(okayIce.size()>0)
        {
            for0(i,okayIce.size())
            {
                cout<<" "<<okayIce[i];
            }
            cout<<endl;
        }
        else cout<<" "<<-1<<endl;
        v.clear();
    }
    return 0;
}




















