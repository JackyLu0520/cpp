#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	//freopen("order.in","r",stdin);
	//freopen("order.out","w",stdout);
	int n,a=0,b=0,c=0,i,j,k;
	cin>>n;
	if(n<14){
		cout<<-1;
		return 0;
	}
	for(i=0;i<n/7;i++)
		for(j=0;j<n/4;j++)
			for(k=0;k<n/3;k++)
				if(i*7+j*4+k*3==n)
					if(min(min(i,j),k)>min(min(a,b),c))
						if(i+j+k>a+b+c){
							a=i;b=j;c=k;
						}
	cout<<a<<' '<<b<<' '<<c;
	return 0;
}
