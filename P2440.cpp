#include<iostream>
using namespace std;
int a[100001],n,k;
int search(int l,int r){
	int mid,i,sum=0;
	mid=(l+r+1)/2;
	for(i=1;i<=n;i++)	sum+=a[i]/mid;
	if(l==r)
		if(sum>=k)	return l;
		else		return 0;
	if(sum>=k)	return search(mid,r);
	else	return search(l,mid-1);
}
int main(){
	int i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cout<<search(1,100000000);
	return 0;
}
