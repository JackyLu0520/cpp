#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,n,k,max,min;
	cin>>n;
	int a[n];
	cin>>a[0];
	max=min=a[0];
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)	max=a[i];
		if(a[i]<min)	min=a[i];
	}
	int b[max-min+1];
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
		b[a[i]-min]++;
	for(i=0;i<max-min+1;i++)
		while(b[i])
		{
			cout<<i+min<<' ';
			b[i]--; 
		}
    return 0;
}
