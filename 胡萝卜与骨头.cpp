#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,k,num=0;
	bool a[31];
	memset(a,true,sizeof(a));
	for(i=1,k=0;k<15;i++)			
	{
		if(i>30)	i=1;
		if(a[i])num++;
		if(num==9)
		{
			a[i]=false;
			k++;
			num=0;
		}
	}
	for(i=1;i<30;i++)
		if(a[i])
			cout<<i<<' ';
	return 0;
}
