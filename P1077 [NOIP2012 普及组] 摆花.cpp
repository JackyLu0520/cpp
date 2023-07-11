#include<bits/stdc++.h>
using namespace std;
const int mod=1000007;
int dp[101],a[101],n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int v=m;v>=1;v--)
			for(int k=1;k<=min(a[i],v);k++)
				dp[v]=(dp[v]+dp[v-k])%mod;
	cout<<dp[m];
	return 0;
}
