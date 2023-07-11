#include<bits/stdc++.h>
using namespace std;
int dp[1000010],a[1000010],n,ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]>=a[j])
				dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
