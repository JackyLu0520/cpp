#include<iostream>
using namespace std;
int main()
{
	int a[5],i,j;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	for(i=0;i<4;i++)
		for(j=0;j<4-i;i++)
			if(a[j+1]>a[j])	
				swap(a[j+1],a[j]); 
	cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4];
}
