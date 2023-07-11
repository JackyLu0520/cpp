#include<iostream>
#include<cstring>
using namespace std;
const int MAX=210;
int a[MAX],x,y,t,i,p;
int main()
{
	cin>>x>>y;
	memset(a,0,sizeof(a));
	a[0]=x;
	for(i=2;i<=y;i++)
	{
		for(p=0;p<=MAX-1;p++)	a[p]*=x;
		for(p=0;p<=MAX-2;p++)
		{
			t=a[p];
			a[p]=t%10;
			a[p+1]+=t/10;
		}
	}
	for(p=MAX-1;a[p]==0;p--)	;
	for(;p>=0;p--)
		cout<<a[p];
	return 0;
}
