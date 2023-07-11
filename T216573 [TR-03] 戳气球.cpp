#include<iostream>
using namespace std;
int n,a[810],f[810][810]={0};
int dp(int l,int r){
	if(f[l][r])	return f[l][r];
	if(r==l+1)	return 0;
	for(int k=l+1;k<r;k++)
		f[l][r]=max(f[l][r],dp(l,k)+dp(k,r)+a[l]*a[k]*a[r]);
	return f[l][r];
}
int main(){
	cin>>n;
	a[0]=a[n+1]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<dp(0,n+1);
	return 0;
}