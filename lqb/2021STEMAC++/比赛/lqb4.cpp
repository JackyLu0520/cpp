#include<bits/stdc++.h>
using namespace std;
int dp[101],a[101],n,ans=0,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0]=0;
	for(int i=1;i<=k;i++){
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
	}
	for(int i=k+1;i<=n;i++){
		dp[i]=1;
		for(int j=k;j<i;j++)
			if(a[i]>a[j]&&a[j]>=a[k])
				dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
