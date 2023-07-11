#include<bits/stdc++.h>
using namespace std;
int a[1000001],n,k;
int search(int l,int r){
	int mid=(l+r+1)/2;
	long long s=0;
	for(int i=1;i<=n;i++)
		if(a[i]>mid)
			s+=a[i]-mid;
	if(l==r)
		if(s>=k)	return l;
		else		return 0;
	if(s>=k)	return search(mid,r);
	else		return search(l,mid-1);
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<search(1,1000000000);
	return 0;
}
