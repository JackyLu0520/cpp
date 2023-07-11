#include<iostream>
using namespace std;
int a[1000001],q[100001];
int search(int l,int r,int n){
	int mid;
	if(l>r)		return -1;
	if(l==r&&a[l]==n)	return l;
	mid=(l+r)/2;
	if(a[mid]==n)	return search(l,mid,n);
	if(a[mid]>n)	return search(l,mid-1,n);
	else		return search(mid+1,r,n);
}
int main(){
	int i,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>q[i];
	for(i=1;i<=m;i++)
		cout<<search(1,n,q[i])<<' ';
	return 0;
}
