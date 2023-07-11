#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,m,n,k,num;
	bool a[101];
	memset(a,true,sizeof(a));
	cin>>m>>n;
	for(i=1,k=0;k<m;i++)			
	{
		if(i>m)	i=1;
		if(a[i])num++;
		if(num==n)
		{
			a[i]=false;
			k++;
			num=0;
			cout<<i<<' ';
		}
	}
	return 0;
}
