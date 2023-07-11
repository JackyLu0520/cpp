#include<bits/stdc++.h>
using namespace std;
int dp[30010]={0},w[25],c[25],n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i]>>c[i];
	for(int i=1;i<=m;i++)
		for(int v=n;v>=1;v--)
			if(v>=w[i])	dp[v]=max(dp[v],dp[v-w[i]]+w[i]*c[i]);
	cout<<dp[n];
	return 0;
} 
