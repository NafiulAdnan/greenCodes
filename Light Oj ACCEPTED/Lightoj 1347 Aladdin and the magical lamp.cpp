#include<bits/stdc++.h>
using namespace std;

#define mem(n,a) memset(n, a, sizeof(n));
#define mx  15005
/// SA[i] denotes the index of the ith suffix array.
/// RA[i] denotes the rank of i'th index

int SA[mx],tempSA[mx];
int RA[mx],tempRA[mx];
int c[mx];
int Phi[mx],PLCP[mx],LCP[mx];
int xyLCP[18][mx],stp ;

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
    stp = 0;
    for(int i=0; i<n; i++)
    {
        RA[i]=str[i];
        SA[i]=i;
        xyLCP[stp][i]=RA[i];
    }
    stp++;

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
        {
            RA[i]=tempRA[i];
            xyLCP[stp][i]= RA[i];
        }
        stp++;

        if(RA[SA[n-1]]==n-1) break;
    }
    stp--;
//    string ss=str;
//
//    for(int i=0; i<n; i++)
//        cout<<i<<" "<<RA[i]<<" "<<SA[i]<<" "<<ss.substr(SA[i])<<endl;

}
//
//void build_LCP()
//{
//    Phi[SA[0]]=-1;
//    for(int i=1; i<n; i++)
//        Phi[SA[i]]=SA[i-1];
//    for(int i=0,L=0; i<n; i++)
//    {
//        if(Phi[i]==-1)
//        {
//            PLCP[i]=0;
//            continue;
//        }
//        while(str[i+L]==str[Phi[i]+L]) L++;
//        PLCP[i]=L;
//        L=max(L-1,0);
//    }
//
//    for(int i=0; i<n; i++)
//    {
//        LCP[i]=PLCP[SA[i]];
//         cout<<i<<" "<<LCP[i]<<endl;
//    }
//}

int find_lcp(int x,int y)
{
    int ret = 0;
    if(x==y)return n-x;
    for(int k = stp; k>=0 && x<n && y<n; k--)
    {
        if(xyLCP[k][x]==xyLCP[k][y])
        {
            x+= (1<<k);
            y+= (1<<k);
            ret+= (1<<k);
        }
    }
    return ret;
}

int getPos(int i, int p1,int p2,int p3)
{
//    cout<<"checking"<<endl;
//    cout<<i<<" "<<p1<<" "<<p2<<" "<<p3<<endl;
    if(i<p1)return 1;
    if(i<p2) return 2;
    return 3;
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&str);
        int p1 = strlen(str);
        strcat(str,"$");

        scanf("%s",&str1);
        strcat(str,str1);
        int p2= strlen(str);
        strcat(str,"@");

        scanf("%s",&str1);
        strcat(str,str1);
        int p3 = strlen(str);
        strcat(str,"*");

        n = strlen(str);

        build_SA();
        //   build_LCP();

        int ans = 0;
        int i=3,j=3;
        int mp[4];
        mp[0]=mp[1]=mp[2]=mp[3]=0;
        int  cnt = 0;

        while(j<n)
        {
          //  cout<<"SEE "<<i<<" "<<j<<" "<<cnt<<endl;
            int pos = getPos(SA[j], p1,p2, p3);
            if(!mp[pos])
            {
                cnt++;
            }

            mp[pos]++;
            if(cnt==3)
            {
                int temp = find_lcp(SA[i],SA[j]);
              //  cout<<i<<"  "<<j<<"   "<<temp<<endl;

                ans = max(ans,temp);
            }
            while(cnt>=3)
            {
                int tpos = getPos(SA[i],p1,p2,p3);
                mp[tpos]--;
                i++;
                if(mp[tpos]==0)
                {
                    cnt--;
                }
                if(cnt==3)
                {
                    int temp = find_lcp(SA[i],SA[j]);
                   // cout<<i<<"  "<<j<<"   "<<temp<<endl;
                    ans = max(ans,temp);
                }
            }
            j++;
        }


        printf("Case %d: %d\n",cs++,ans);
    }
}



