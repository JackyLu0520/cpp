#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	double x,y;
}a,b,c,d;double p,q,r;
double gougu(node n1,node n2)
{
	return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}
node find(node xx,node yy,double k)
{
	node no;no.x=(yy.x-xx.x)*k+xx.x;no.y=(yy.y-xx.y)*k+xx.y;
	return no;
}
double checkplus(double x,double y)
{
	node n1=find(a,b,x),n2=find(c,d,y);
	return gougu(a,n1)/p+gougu(n1,n2)/r+gougu(n2,d)/q;
}
double check(double x)
{
	double l=0.0,r=1.0;
	while(r-l>=0.0000001)
	{
		double mid1=l+(r-l)/3.0,mid2=r-(r-l)/3.0;
		if(checkplus(x,mid1)>checkplus(x,mid2))l=mid1;
		else r=mid2;
	}
	return checkplus(x,l);
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
	scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
	scanf("%lf%lf%lf%lf",&c.x,&c.y,&d.x,&d.y);
	scanf("%lf%lf%lf",&p,&q,&r);
	double l=0.0,r=1.0;
	while(r-l>=0.0000001)
	{
		double mid1=l+(r-l)/3.0,mid2=r-(r-l)/3.0;
		if(check(mid1)>check(mid2))l=mid1;
		else r=mid2;
	}
	printf("%.2lf",check(l));
	return 0;
}
