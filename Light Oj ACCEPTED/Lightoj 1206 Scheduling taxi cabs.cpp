
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>


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
#define MAX 505

int n,m;
vector<int>v[MAX*MAX];
bool col[MAX*MAX];
int match[MAX*MAX];

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

    for0(i,n)
    {
        if(v[i].size()==0)continue;
        mem(col);
        if(dfs(i))
        {
            cnt++;
        }
    }
    return cnt;
}
void addEdge(int a,int b)
{
    v[a].pb(b);
}
struct taxi
{
    int hr,  mnt;
    int inX,inY;
    int toX,toY;
    int travelTime;
};

vector<taxi>votvoti;
bool timePore(int f,int s)
{
    int timeLagse = votvoti[f].hr * 60 + votvoti[f].mnt + votvoti[f].travelTime;
    int aroLagbo = abs(votvoti[f].toX-votvoti[s].inX) + abs(votvoti[f].toY-votvoti[s].inY);
    int totalTime = timeLagse+aroLagbo;
    int pouchtamAt = votvoti[s].hr * 60 + votvoti[s].mnt;

    return (pouchtamAt>totalTime);
}

int main()
{
    int a,b,cs=1;
    FastRead;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for0(i,n)
        {
            taxi tempu;
            char ch;
            cin>>tempu.hr>>ch>>tempu.mnt>>tempu.inX>>tempu.inY>>tempu.toX>>tempu.toY;
            tempu.travelTime = abs(tempu.inX-tempu.toX) + abs(tempu.inY-tempu.toY);
            votvoti.pb(tempu);
        }


        for0(f,n)
        {
          //  cout<<"h "<<f<<endl;
            for(int s=f+1; s<n; s++)
            {
            //    cout<<"G"<<endl;
                if(timePore(f,s))
                {
         //           cout<<"a "<<endl;
                    addEdge(f,s);
                }
                else if(timePore(s,f))
                {    //                cout<<"B "<<endl;
////
                    addEdge(s,f);
                }
                //cout<<"a "<<f<<" "<<s<<endl;
            }
        }
        cout<<"Case "<<cs++<<": ";
    //    BICOLOR();
        cout<<n-BPM()<<endl;
        votvoti.clear();
        for0(i,n)v[i].clear();
    }

}









