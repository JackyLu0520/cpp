#include<bits/stdc++.h>
using namespace std;
int dp[102],dp1[102],a[102],n,ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
	}
	for(int i=n;i>=1;i--){
		dp1[i]=1;
		for(int j=n;j>i;j--)
			if(a[i]>a[j])
				dp1[i]=max(dp1[i],dp1[j]+1);
		ans=max(ans,dp[i]+dp1[i]-1);
	}
	cout<<n-ans;
	return 0;
}
