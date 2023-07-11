#include<iostream>
using namespace std;
int main()
{
	int n,a[100],b[100],m=10000,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]<m)	m=a[i];
		c+=m;
		m+=b[i];
	}
	cout<<c;
	return 0;		
}
