#include<iostream>
#include<algorithm>
#define uint unsigned int
using namespace std;
/*uint gcd(uint a,uint b)
{
	return b?gcd(b,a%b):a;
}*/
uint lcm(uint x,uint y)
{
	int a=x,b=y,i;
	if(a>b)	swap(a,b);
	for(i=1;b*i%a==0;i++)	{}
	return b*i;
}
/*uint lcm1(uint x,uint y)
{
	return x*y/gcd(x,y);
}*/
int main()
{
	uint x,y;
	cin>>x>>y;
	cout<<lcm(x,y);
	return 0;
}
