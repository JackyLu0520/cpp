#include<iostream>
#include<cmath>
using namespace std;
int weishu(int a[])
{
	int i;
	for(i=10000-1;a[i]!=0;i--)
	return i;
}
int main()
{
	int a[10000]={1},b[10000]={1},c[10000],i,n,j,jin,maxw,num;
	cin>>n;
	for(i=3;i<n;i++)
	{
		jin=0,maxw=max(weishu(a),weishu(b));
		for(j=0;j<=maxw+1;j++)
		{
			num=a[j]+b[j]+jin;
			c[j]=num%10;
			jin=num/10;
		}
		for(j=0;j<=maxw;j++)	a[j]=b[j],b[j]=c[j];
	}
	for(i=maxw+1;i>=0;i--) if(c[j]) break;
	for(;i>=0;i++)
		cout<<c[i];
	return 0;
}
