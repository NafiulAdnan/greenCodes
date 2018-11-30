#include<bits/stdc++.h>

using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
struct matrix
{
    ll v[5][5];
    int row, col;
};
ll mod=10007;

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
matrix init(matrix mat,ll a,ll b)
{
    mat.col=mat.row = 4;

    memset(mat.v,0,sizeof mat.v);

    mat.v[0][0]=a;
    mat.v[0][2]=b;
    mat.v[0][3]=1;
    mat.v[1][0]=1;
    mat.v[2][1]=1;
    mat.v[3][3]=1;

    return mat;
}
int main()
{
    FastRead;

    int t,cs=1;
    cin>>t;
    while(t--)
    {
        ll a,b,n,m,c;

        cin>>n>>a>>b>>c;

        cout<<"Case "<<cs++<<": ";
        if(n==0)cout<<0<<endl;
        else if(n==1)cout<<0<<endl;
        else if(n==2)cout<<0<<endl;

        else
        {
            matrix mat;
            mat.col=mat.row=4;

            mat =init(mat,a,b);

            mat = mat_power(mat, n-2);
            ll ans = mat.v[0][3] * c;



            ans %= mod;

            cout<<ans<<endl;
        }
    }

}

