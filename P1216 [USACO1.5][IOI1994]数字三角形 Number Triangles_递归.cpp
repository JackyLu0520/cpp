#include<bits/stdc++.h>
using namespace std;
const int MAXR=1002;
int r,t[MAXR][MAXR],dp[MAXR][MAXR];
int dfs(int x,int y){
	if(dp[x][y]!=-1)	return dp[x][y];
	if(x!=r)	dp[x][y]=t[x][y]+max(dfs(x+1,y),dfs(x+1,y+1));
	else	dp[x][y]=t[x][y];
	return dp[x][y];
}
int main(){
	cin>>r;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=i;j++)
			cin>>t[i][j];
	memset(dp,-1,sizeof(dp));
	cout<<dfs(1,1);
	return 0;
}
