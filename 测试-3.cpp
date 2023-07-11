#include<iostream>
using namespace std;
int maxn=0,n,a[20];
bool f[21]={0};
int weishu(int num)
{
	int m=num,wei=1;
	while(m)	m/=10,wei*=10;
	return wei;
}
void fun(int lv,long long num,int j)
{
	f[j]=1;
	if(lv==n)
	{ 
		if(maxn<num)
			maxn=num;
	} 
	else
		for(int i=0;i<n;i++)
		{
			if(f[i]==1)
				fun(lv+1,weishu(a[i])*num+a[i],i);
		}
	f[j]=0;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	fun(0,0,0);
	cout<<maxn;
	return 0;
}
