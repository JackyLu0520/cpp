#include<iostream>
using namespace std;
int main()
{
	int i,j,a[6]={0,1,2,3,4,5};
	i=1;
	cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<a[5]<<' '<<endl;
	for(i=2;i<=10;i++)
	{
		for(j=0;j<=4;j++)
			a[j]=a[j+1];
		a[5]=a[0];
		cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<a[5]<<' '<<endl;		
	} 
	return 0;
} 
