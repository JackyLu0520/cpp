#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
	float a[n+1];
	for(i=1;i<=n;i++)
		cin>>a[i];	 
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(a[j+1]<a[j])
				swap(a[j],a[j+1]);
    for(i=1;i<=n;i++)
    	cout<<a[i]<<"  ";
    return 0;
}
