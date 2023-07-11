#include<bits/stdc++.h>
using namespace std;
int a[1000010],q,n,m;
int Search(){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]>=q)	r=mid;
		else			l=mid+1;
	}
	if(a[l]==q)	return l;
	else		return -1;
}
int main(){
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++){
		cin>>q;
		cout<<Search()<<' ';
	}
	return 0;
} 
