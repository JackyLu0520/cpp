#include<iostream>
#include<cmath>
using namespace std;
int max10(int a[],int n)
{
	return n==1?a[0]:max(max10(a,n-1),a[n]);
}
int main()
{
	int i,a[10],arr[2147483648UL],t,j=0,k;
	cin>>t;
	for(i=0;i<t;i++)
		cin>>a[i];
	for(i=0;i<max10(a,10);i++)
	{
		k=1;
		for(;k<=i;j++)
		{
			arr[j]=k;
			k++;
		}
	}
	for(i=0;i<t;i++)
		cout<<arr[a[i]];
	return 0;
}
