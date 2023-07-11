#include<iostream>
//#include<stdio.h>
using namespace std;
int main()
{
	//freopen("order.in","r",stdin);
	//freopen("order.out","w",stdout);
	int n,a=-1,b=-1,c=-1,i,j,k,t,m;
	bool f=false;
	cin>>n;
	for(t=n/14;t>=0;t--)
	{
		m=n-t*14;
		for(i=0;i<=m/7;i++)
			for(j=0;j<=(m-i*7)/4;j++)
				if((m-i*7-j*4)%3==0)
				{
						
				    k=(m-i*7-j*4)/3;
					if(i+j+k>a+b+c)
					{
						f=true;
						a=i;b=j;c=k;
					}
				}
		if(f)
		{
			a+=t;
			b+=t;
			c+=t;
			break;
		}	
	}
	if(f)
		cout<<a<<' '<<b<<' '<<c;
	else
		cout<<-1;
	return 0;
}
