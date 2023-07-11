#include<iostream>
using namespace std;
int a[1000001],n,m;
int maxa(){
	int ans=0;
	for(int i=1;i<=n;i++)
		if(ans<a[i]) 
			ans=a[i];
	return ans;
}
int search(int l,int r){
	int mid,i;long long sum=0;
	mid=(l+r+1)/2;
	for(i=1;i<=n;i++)	if(a[i]>mid)	sum+=a[i]-mid;
	if(l==r&&sum>=m)	return l;
	if(sum>=m)	return search(mid,r);
	else	return search(l,mid-1);
}
int main(){
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cout<<search(0,maxa());
	return 0;
}
