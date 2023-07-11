#include<bits/stdc++.h>
using namespace std;
vector<int> adj[21];
int w[21],n,Next[21],ans,start,dp[21];
int DP(int u){
	if(dp[u])	return dp[u];
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		int t=DP(v);
		if(t>dp[u]){
			dp[u]=t;
			Next[u]=v;
		}
	}
	dp[u]+=w[u];
	return dp[u];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			int t;
			cin>>t;
			if(t)	adj[i].push_back(j);
		}
	for(int i=1;i<=n;i++){
		dp[i]=DP(i);
		if(dp[i]>ans){
			ans=dp[i];
			start=i;
		}
	}
	while(start){
		cout<<start<<' ';
		start=Next[start];
	}
	cout<<endl<<ans;
	return 0;
} 
