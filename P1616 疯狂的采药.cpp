#include<bits/stdc++.h>
using namespace std;
long long dp[10000001],w[10001],c[10001],t,m;
int main(){
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i]>>c[i];
	for(int i=1;i<=m;i++)
		for(int v=1;v<=t;v++)
			if(v>=w[i])	dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
	cout<<dp[t];
	return 0;
} 
