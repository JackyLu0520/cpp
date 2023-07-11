#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],sum;
string s,s1;
int main(){
	int i,j;
	cin>>s;
	s1=s;
	reverse(s1.begin(),s1.end());
	for(i=1;i<=s.size();i++)
		for(j=1;j<=s1.size();j++)
			if(s[i-1]==s1[j-1])	dp[i][j]=dp[i-1][j-1]+1;
			else		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	cout<<dp[s.size()][s1.size()];
	return 0;
}
