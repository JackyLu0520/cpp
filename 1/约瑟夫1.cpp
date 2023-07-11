#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,m,n,out,num;
	bool a[101];
	cin>>m>>n;
	memset(a,true,sizeof(a));
	for(i=1,out=0;out<m;i++)
	{
		if(i>m)	i=1;
		if(a[i])	num++;
		if(num==n)	
		{
			a[i]=false;
			out++;
			num=0;
			cout<<i<<' ';
		}
	}
	return 0;
}
