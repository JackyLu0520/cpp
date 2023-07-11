#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,m=3,n,k,num,ans;
	bool a[101];
	memset(a,true,sizeof(a));
	cin>>n;
	for(i=1,k=0;k<m;i++)			
	{
		if(i>m)	i=1;
		if(a[i])num++;
		if(num==n)
		{
			a[i]=false;
			k++;
			num=0;
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
