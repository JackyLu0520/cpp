#include<iostream>
using namespace std;
int main()
{
	int i,j,n,k;
	cin>>n;
	float a[n],t;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
			if(a[j]<a[i])
				break;
		if(j!=i-1)
		{
			t=a[i];
			for(k=i-1;k>j;k--)
				a[k+1]=a[k];
			a[k+1]=t;
		}
	}
    for(i=0;i<n;i++)
    	cout<<a[i]<<" ";
    return 0;
}
