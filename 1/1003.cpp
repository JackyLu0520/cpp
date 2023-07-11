#include<iostream>
using namespace std;
const int MAX=100000;
int main()
{
	int a[MAX],b[MAX],g[MAX],k[MAX];
	int n,x,y,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	cin>>x>>y;
	for(i=n;i>0;i--)	
		if(x>=a[i]&&x<=(g[i]+a[i])&&y>=b[i]&&y<=(k[i]+b[i]))
		{
			cout<<i;
			return 0; 
		}
	cout<<-1;
	return 0;	
}
