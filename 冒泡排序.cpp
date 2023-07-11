#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,a[10000],i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=n-1;i>0;i--)
		for(j=0;j<i;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}
