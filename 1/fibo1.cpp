#include<iostream>
using namespace std;
int main()
{
	long long a[2]={1,0},b[2]={1,0},c[2];
	int i;
	for(i=2;i<100;i++)
	{
		c[0]=(a[0]+b[0])%100000000000;
		c[1]=a[1]+b[1]+(a[0]+b[0])/100000000000;
		a[0]=b[0];
		a[1]=b[1];
		b[0]=c[0];
		b[1]=c[1];
		//cout<<c[1]<<'-'<<c[0]<<' ';
	}
	cout<<c[1]<<c[0];
	return 0;
}
