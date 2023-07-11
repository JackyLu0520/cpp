#include<bits/stdc++.h>
using namespace std;
int dp[1001],w[101],c[101],t,m;
int main(){
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i]>>c[i];
	for(int i=1;i<=m;i++)
		for(int v=t;v>=1;v--)
			if(v>=w[i])	dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
	cout<<dp[t];
	return 0;
} 
