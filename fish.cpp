#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,n,i,m=10000,s=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		s+=min(a,m);
		m=b+min(a,m);
	}
	cout<<s;
	return 0;
}
