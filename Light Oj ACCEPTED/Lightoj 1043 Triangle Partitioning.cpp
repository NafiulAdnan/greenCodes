#include<bits/stdc++.h>
using namespace std;


double trapiArea(double a,double b, double c,double d)
{
    double h = b*b - ((b*b-d*d + (a-c)*(a-c))/(2*(a-c)))*((b*b-d*d + (a-c)*(a-c))/(2.00*(a-c)));
    h = sqrt(h);

    double area = h * ((a+c)/2.00);
    return area;
}


int main()
{
    int t,cs=1;
    scanf("%d",&t);

    while(t--)
    {
        double ab,ac,bc, rat, ad,de,ec,ae;

        scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&rat);


        double low = 0, high = max(ab,max(bc,ac));
        double mid;
        while( high - low >= .00000000001 )
        {
            mid = (high+low)/2.00;
         ///   cout<<mid<<" ";
            ad =mid;
            double adb = ad/ab;

            ae = ac * adb;
            de = bc * adb;
            double p = (ae+ad+de)/2.0;
            double triv = sqrt(p *(p-ae)*(p-de)*(p-ad) );
            double bd = ab-ad;
            double ec = ac-ae;
            double trp = trapiArea(bc, bd, de, ec);

            double dif = triv/trp;

            if(abs(dif-rat) ==0)break;

         //   cout<<triv<<" "<<trp<<endl;


            if(dif>rat)high=mid;
            else low = mid;

        }

        printf("Case %d: %.10f\n",cs++,mid);


    }
}
