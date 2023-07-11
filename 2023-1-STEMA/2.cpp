#include<bits/stdc++.h>
using namespace std;
int n,a[110],ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<n;i++)
		ans=max(ans,a[i-1]+a[i]+a[i+1]);
	cout<<ans;
	return 0;
}