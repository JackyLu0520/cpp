#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	//freopen("order.in","r",stdin);
	//freopen("order.out","w",stdout);
	int n,a=0,b=0,c=0,i,j,k;
	cin>>n;
	if(n<14)
	{
		cout<<-1;
		//fclose(stdin);
		//fclose(stdout);
		return 0;
	}
	for(i=1;i<n/7;i++)
		for(j=1;j<n/4;j++)
			for(k=1;k<n/3;k++)
				if(i*7+j*4+k*3==n)
					if(min(min(a,b),c)<min(min(i,j),k))
						if(a+b+c<i+j+k)
						{
							a=i;
							b=j;
							c=k;
						}
	cout<<a<<' '<<b<<' '<<c;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
