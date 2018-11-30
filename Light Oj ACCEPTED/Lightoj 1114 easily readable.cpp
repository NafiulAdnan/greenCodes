/*
Trie implementation using array, faster and takes less memory.
Each node can contain arbitrary data as needed for solving the problem.
The ALPHABET, MAX and scale() may need tuning as necessary.
*/

#include <bits/stdc++.h>
using namespace std;



const int ALPHABET = 26*2;
const int MAX = 100000;

// for mapping items form 0 to ALPHABET-1
int scale(char x)
{
    if(x>='a' && x<='z')
        return x-'a' + 26;
    return x-'A';
}

struct TrieTree
{
    int n, root;
    int next[MAX][ALPHABET];
    //int times[MAX];
    long long data[MAX]; // there can be more data fields

    void init()
    {
        root = 0, n = 1;
        data[root] = 0;
        //  times[root] = 0;
        memset(data,0,sizeof(data));
        memset(next[root], -1, sizeof(next[root]));
        // memset(times,0,sizeof(times));
    }

    void insert(char *s)
    {
        int curr = root, i, k;
        for(i = 0; s[i]; i++)
        {
            k = scale(s[i]);
            if(next[curr][k] == -1)
            {
                next[curr][k] = n;
                // data[n] = s[i]; // optional
                memset(next[n], -1, sizeof(next[n]));
                n++;
            }
            curr = next[curr][k];
        }

//        cout<<" added "<<curr<<endl;

        data[curr] ++; // sentinel, optional
    }

    long long find(char *s)
    {
//        cout<<s<<endl;
        int curr = root, i, k;
        for(i = 0; s[i]; i++)
        {
            k = scale(s[i]);
            if(next[curr][k] == -1) return false;
            curr = next[curr][k];
        }
        return (data[curr]);
    }

} tree;

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        tree.init();
        char tmp[10005],  s[10005];
        scanf("%d",&n);


        for(int i=0; i<n; i++)
        {
            scanf("%s",&s);

            {
                char fs = s[0], ls = s[strlen(s)-1];

                s[0]='A',s[strlen(s)-1]='z';

                sort(s,s+strlen(s));
                s[0]=fs,s[strlen(s)-1]=ls;

                tree.insert(s);
            }
        }

        int q;
        scanf("%d",&q);

        getchar();
printf("Case %d:\n",cs++);
        while(q--)
        {
            long long int ans=1;

            gets(tmp);

            char *pnt;
            pnt = strtok(tmp," ");

            while(pnt!=NULL)
            {
                strcpy(s,pnt);

                char fs = s[0], ls = s[strlen(s)-1];
                s[0]='A',s[strlen(s)-1]='z';

                sort(s,s+strlen(s));

                s[0]=fs,s[strlen(s)-1]=ls;
                long long a = tree.find(s);

//                cout<<a<<endl;
                ans *= a;

                pnt = strtok(NULL," ");

            }
            printf("%lld\n",ans);
        }

    }
}


