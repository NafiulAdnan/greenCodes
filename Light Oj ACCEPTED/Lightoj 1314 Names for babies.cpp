#include<bits/stdc++.h>
using namespace std;

#define mem(n,a) memset(n, a, sizeof(n));
#define mx  10005
/// SA[i] denotes the index of the ith suffix array.
/// RA[i] denotes the rank of i'th index

int SA[mx],tempSA[mx];
int RA[mx],tempRA[mx];
int c[mx];
int Phi[mx],PLCP[mx],LCP[mx];
char str[mx],str1[mx];
int n;
void counting_sort(int k)
{
    int maxi=max(n,300);
    mem(c,0);
    for(int i=0; i<n; i++)
    {
        int a=i+k<n?RA[i+k]:0;
        c[a]++;
    }
    for(int i=0,sum=0; i<maxi; i++)
    {
        int x=c[i];
        c[i]=sum;
        sum+=x;
    }

    for(int i=0; i<n; i++)
    {
        int a=SA[i]+k<n?RA[SA[i]+k]:0;
        int b=c[a];
        c[a]++;
        tempSA[b]=SA[i];
    }

    for(int i=0; i<n; i++)
        SA[i]=tempSA[i];
}

void build_SA()
{
    for(int i=0; i<n; i++)
    {
        RA[i]=str[i];
        SA[i]=i;
    }

    for(int k=1; k<n; k*=2)
    {
        counting_sort(k);
        counting_sort(0);

        int r=0;
        tempRA[SA[0]]=r=0;

        for(int i=1; i<n; i++)
        {
            if(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])
                tempRA[SA[i]]=r;
            else
                tempRA[SA[i]]=++r;
        }

        for(int i=0; i<n; i++)
            RA[i]=tempRA[i];

        if(RA[SA[n-1]]==n-1) break;
    }
    string ss=str;
//
//    for(int i=0; i<n; i++)
//        cout<<i<<" "<<RA[i]<<" "<<SA[i]<<" "<<ss.substr(SA[i])<<endl;

}

void build_LCP()
{
    Phi[SA[0]]=-1;
    for(int i=1; i<n; i++)
        Phi[SA[i]]=SA[i-1];
    for(int i=0,L=0; i<n; i++)
    {
        if(Phi[i]==-1)
        {
            PLCP[i]=0;
            continue;
        }
        while(str[i+L]==str[Phi[i]+L]) L++;
        PLCP[i]=L;
        L=max(L-1,0);
    }

    for(int i=0; i<n; i++)
    {
        LCP[i]=PLCP[SA[i]];
        // cout<<i<<" "<<LCP[i]<<endl;
    }

}
int getPos(int i, int p1,int p2)
{
    if(i<=p1)return 1;
    return 2;

}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&str);
        strcat(str,"$");

        n = strlen(str);
        int low, high;
        scanf("%d%d",&low, &high);

        low--,high--;

        build_SA();
        build_LCP();

        int ans = 0;
        for(int i=1; i<n; i++)
        {
            int len = n - SA[i]-1;
            int mil = LCP[i];

            int posSub = len - mil ;

            int st = max(low, LCP[i]);
            int nd = min(high, len-1);

        //    cout<<st<<" "<<nd<<" "<<posSub<<" "<<nd-st+1<<endl;

            ans += max(0,nd-st+1);

        }

        printf("Case %d: %d\n",cs++,ans);
    }
}


