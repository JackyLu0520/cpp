#include<iostream> 
#include<cmath>
using namespace std;
int main()
{
	double x,y;
	long long a,b,i,j;
	do
	{
		cin>>x;
	}while(x>=1||x<=0);
	a=1;
	y=x;
	while(fabs(y-(int)y)>1e-10)
	{
		a*=10;
		y=x*a;
	}
	b=y;
	cout<<b<<'/'<<a<<endl;
	for(i=b;i>=1;i--)
		if(b%i==0&&a%i==0)
		{
			j=i;
			break;
		}
	cout<<b/j<<'/'<<a/j;
	return 0;
}
