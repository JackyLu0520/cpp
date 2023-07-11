#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j;
	cin>>n;
	float a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[m])
				m=j;
		if(m!=i)
			swap(a[i],a[m]);
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
