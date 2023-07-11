#include<bits/stdc++.h>
using namespace std;
int dp[101][1001],w[101],c[101],t,m;
int main(){
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i]>>c[i];
	for(int i=1;i<=m;i++)
		for(int v=1;v<=t;v++)
			if(v==0)	dp[i][v]=0;
			else if(v<w[i])	dp[i][v]=dp[i-1][v];
			else	dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
	cout<<dp[m][t];
	return 0;
} 
