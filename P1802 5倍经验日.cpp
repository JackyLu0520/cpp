#include<bits/stdc++.h>
using namespace std;
int dp[101][1001],w[101],c[101],c1[101],t,m;
int main(){
	cin>>m>>t;
	for(int i=1;i<=m;i++)
		cin>>c1[i]>>c[i]>>w[i];
	for(int i=1;i<=m;i++)
		for(int v=1;v<=t;v++)
			if(v<w[i])	dp[i][v]=dp[i-1][v]+c1[i];
			else	dp[i][v]=max(dp[i-1][v]+c1[i],dp[i-1][v-w[i]]+c[i]);
	cout<<dp[m][t]*5LL;
	return 0;
} 
