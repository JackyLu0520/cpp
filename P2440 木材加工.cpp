#include<bits/stdc++.h>
using namespace std;
int a[100001],n,k;
int count(int m){
	int s=0;
	for(int i=1;i<=n;i++)
		s+=a[i]/m;
	return s;
}
int search(int l,int r){
	int mid=(l+r+1)/2;
	int cnt=count(mid);
	if(l==r)
		if(cnt>=k)	return l;
		else		return 0;
	if(cnt>=k)	return search(mid,r);
	else		return search(l,mid-1);
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<search(1,100000000);
	return 0;
}
