#include<bits/stdc++.h>

using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
struct matrix
{
    ll v[7][7];
    int row, col;
};
ll mod;
  ll a1,a2,b1,b2,c1,c2,n,m;

matrix mat_multy(matrix a, matrix b)
{
    matrix r;
    r.row =a.row;
    r.col =b.col;

    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            ll sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum += a.v[i][k] * b.v[k][j];
                sum %= mod;
            }
            r.v[i][j] =sum;
        }
    }
    return r;
}

matrix mat_power(matrix mat, int p)
{
    if(p==1)return mat;
    if(p%2)
        return mat_multy(mat, mat_power(mat,p-1));
    matrix ret = mat_power(mat,p/2);
    ret = mat_multy(ret,ret);
    return ret;
}
matrix init(matrix mat)
{
    mat.col=mat.row = 6;

    memset(mat.v,0,sizeof mat.v);

    mat.v[0][0]=a1;
    mat.v[0][1]=b1;
    mat.v[0][5]=c1;

    mat.v[1][0]=1;
    mat.v[2][1]=1;

    mat.v[3][2]=c2;
    mat.v[3][3]=a2;
    mat.v[3][4]=b2;
    mat.v[4][3]=1;
    mat.v[5][4]=1;

    return mat;
}
int main()
{
    FastRead;

    int t,cs=1;
    cin>>t;
    while(t--)
    {

        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;
        ll f[5],g[5];
        cin>>f[0]>>f[1]>>f[2];
        cin>>g[0]>>g[1]>>g[2];

        int q;
        cin>>mod;
        cin>>q ;

        cout<<"Case "<<cs++<<":"<<endl;


        while(q--)
        {
            cin>>n;

            if(n<=2)
            {
                cout<<f[n]%mod<<" "<<g[n]%mod<<endl;
                continue;
            }
            matrix mat;
            mat.col=mat.row=6;

            mat =init(mat);

            mat = mat_power(mat, n-2);

            ll ans1 = mat.v[0][0] * f[2] + mat.v[0][1] * f[1]  + mat.v[0][5]*g[0]  + mat.v[0][2] * f[0] + mat.v[0][3]*g[2] + mat.v[0][4] * g[1];
            ll ans2 = mat.v[3][0] * f[2] + mat.v[3][1] * f[1]  + mat.v[3][5]*g[0]  + mat.v[3][2] * f[0] + mat.v[3][3]*g[2] + mat.v[3][4] * g[1];


            ans1 %= mod;
            ans2 %= mod;

            cout<<ans1<<" "<<ans2<<endl;
        }
    }

}

