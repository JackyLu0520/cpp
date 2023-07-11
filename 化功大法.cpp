#include<iostream> 
#include<cmath>
using namespace std;
unsigned int gcd(unsigned int a,unsigned int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	double x,y;
	long long a,b;
	cin>>x;
	a=1;
	y=x;
	while(fabs(y-(int)y)>1e-10){a*=10;y=x*a;}
	b=y;
	cout<<b<<'/'<<a<<endl;
	cout<<b/gcd(a,b)<<'/'<<a/gcd(a,b);
	return 0;
}
