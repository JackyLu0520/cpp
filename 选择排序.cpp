#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,a[10000],m,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++){
		m=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[m])
				m=j;
		if(m!=i)
			swap(a[i],a[m]);
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}
