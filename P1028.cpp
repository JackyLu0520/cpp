#include<iostream>
using namespace std;
int a[1001],n,i,j;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i/2;j++)
			a[i]+=a[j];
		a[i]++;
	}
	cout<<a[n];
	return 0;
}
