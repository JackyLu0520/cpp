#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,m=30,n=9,out,num;
	bool a[101];
	memset(a,true,sizeof(a));
	for(i=1,out=0;out<15;i++)
	{
		if(i>m)	i=1;
		if(a[i])	num++;
		if(num==n)	
		{
			a[i]=false;
			out++;
			num=0;
		}
	}
	for(i=1;i<=m;i++)
		if(a[i])
			cout<<i<<' ';
	return 0;
}
