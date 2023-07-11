#include<bits/stdc++.h>
using namespace std;
int search(int a[],int l,int r,int k){
	int mid=(l+r)/2;
	cout<<mid<<endl;
	if(l>r)	return -1;
	if(l==r&&a[l]==k)	return l;
	if(k==a[mid])	search(a,l,mid,k);
	else if(k<mid)	search(a,l,mid-1,k);
	else if(k>mid)	search(a,mid+1,r,k);
}
int main(){
	int n,m,a[1000001],k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>k;
		cout<<search(a,1,n,k);
	}
	return 0;
} 
