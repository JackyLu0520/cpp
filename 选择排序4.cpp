#include<iostream>
using namespace std;
int main()
{
	int a[5],i,j,m;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	for(i=0;i<4;i++)
	{
		m=i;
		for(j=i+1;j<5;j++)
			if(a[j]>a[m])	m=j;
		if(m!=i)	swap(a[i],a[m]);	 
	}
	cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4];
	return 0;
}
