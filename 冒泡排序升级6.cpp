#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m,l;
	cin>>n;
	float a[n+1];
	for(i=1;i<=n;i++)
		cin>>a[i];
	bool ok;
	l=n-1;	 
	for(i=1;i<=n-1;i++)
	{
		ok=true;
		m=l;
		for(j=1;j<=m;j++)
			if(a[j+1]<a[j])
			{
				swap(a[j],a[j+1]);
				ok=false;
				l=j;
			}
		if(ok)	break;
	}
    for(i=1;i<=n;i++)
    	cout<<a[i]<<" ";
    return 0;
}
