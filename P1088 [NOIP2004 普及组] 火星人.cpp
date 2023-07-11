#include<bits/stdc++.h>
using namespace std;
bool next_p(int a[],int n){
	int i,j,k;
	if(n<2)	return 0;
	for(i=n-2;i>=0;i--){
		j=i+1,k=n-1;
		if(a[i]>=a[j])	continue;
		while(a[i]>=a[k])	k--;
		swap(a[i],a[k]);
		reverse(a+j,a+n);
		return 1;
	}
	reverse(a,a+n);
	return 0;
}
int main(){
	int a[10010],n,m,i;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<m;i++)
		next_p(a,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}
