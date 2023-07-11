#include<iostream>
using namespace std;
#define uint unsigned int
uint gcd(uint a,uint b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	uint x,y;
	cin>>x>>y;
	cout<<gcd(x,y);
	return 0;
}

