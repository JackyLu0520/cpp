#include<iostream>
using namespace std;
int n,a[210],f[210][210]={0},Max=0;
int dp(int l,int r){
	if(f[l][r])	return f[l][r];
	if(r==l+1)	return 0;
	for(int k=l+1;k<r;k++)
		f[l][r]=max(f[l][r],dp(l,k)+dp(k,r)+a[l]*a[k]*a[r]);
	return f[l][r];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1;i<=n;i++)
		Max=max(Max,dp(i,n+i));
	cout<<Max;
	return 0;
}