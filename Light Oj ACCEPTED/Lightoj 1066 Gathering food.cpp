#include<bits/stdc++.h>
using namespace std;

char mxch;

int x[]= {1,-1,0,0};
int y[]= {0,0,1,-1};

int ans,r,c,myI,myJ,ti,tj;
char grd[12][12];
int lev[12][12],n;
bool col[12][12];
bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=n)return 0;
    if(grd[i][j]=='#'||col[i][j])return 0;
    return 1;
}
int bfs(int i, int j,char nxtchr)
{
    if(nxtchr>mxch)return 0;

    queue< pair<int,int> > q;

    q.push({i,j});
    memset(lev,0,sizeof(lev));
    memset(col,0,sizeof(col));

    lev[i][j]=0;
    bool ok  = 0;
    while(!q.empty())
    {
    //    cout<<nxtchr<<" ";
        ti = q.front().first;
        tj= q.front().second;
        col[ti][tj]=1;

        q.pop();

        for(int i=0; i<4; i++)
        {
            myI = ti + x[i];
            myJ = tj + y[i];

            if(valid(myI,myJ))
            {
                if(grd[myI][myJ]=='.')
                {
                    lev[myI][myJ]=lev[ti][tj]+1;
                    q.push({myI,myJ});
                }
                else if(grd[myI][myJ]==nxtchr)
                {
                    ans += lev[ti][tj]+1;
                    nxtchr++;
                    if(nxtchr>mxch)return ans;
                    grd[myI][myJ]='.';

                    while(!q.empty())
                    {
                        q.pop();
                    }

                    memset(lev,0,sizeof(lev));
                    memset(col,0,sizeof(col));

                    lev[myI][myJ]=0;
                    q.push({myI,myJ});
                    break;
                }
            }
        }
    }
    return -1;

//    if(ok)
//    {
//        bfs(myI,myJ,++nxtchr);
//    }
//    else
//    {
//        ans = -1;
//        return;
//    }

}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        myI=-1,myJ=-1;
        scanf("%d",&n);
        mxch = '0';
        for(int i=0; i<n; i++)
        {
            scanf("%s",&grd[i]);
            for(int j=0; j<n; j++)
            {
                if(grd[i][j]=='A')
                {
                    myI = i,myJ = j;
                }
                if(grd[i][j]>='A'&&grd[i][j]<='Z')mxch = max(mxch,grd[i][j]);
            }
        }
        printf("Case %d: ",cs++);
        if(mxch<='A')
        {
            printf("0\n");
            continue;
        }
        if(myI==-1)
        {
            printf("Impossible\n");
            continue;
        }
        ans = 0;

     //   (myI==-1&&mxch>'A')
     grd[myI][myJ]='.';
        ans = bfs(myI,myJ,'B');
        if(ans==-1)printf("Impossible\n");
        else printf("%d\n",ans);


    }
}
