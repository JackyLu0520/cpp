#include<iostream>
using namespace std;
int main()
{
	int m,b,m1,n;
	bool a[4];
	for(m=1;m<=4;m++)
		for(b=1;b<=4;b++)
			for(m1=1;m1<=4;m1++)
			{
				n=10-m-b-m1;
				if(m*b*m1*n==1*2*3*4)
				{
					a[0]=((m==1)+(b==4)+(m1==3)+(n==2)==2);
					a[1]=((m==4)+(b==1)+(m1==2)+(n==3)==2);
					a[2]=((m==3)+(b==4)==1);
					a[3]=((m==1)+(b==3)+(m1==2)+(n==4)==2);
					if(a[0]&&a[1]&&a[2]&&a[3])
					{
						cout<<m<<' '<<b<<' '<<m1<<' '<<n;
						break;
					}
				}
			}
	return 0;
}
