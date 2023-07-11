#include<iostream>
using namespace std;
int n,a[100],b[100],i,j;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
	        if(a[i]>a[j])
				b[i]++;
	for(i=0;i<n;i++)
		cout<<b[i]<<' ';
	return 0;				
}//P1428
