#include<bits/stdc++.h>
using namespace std;
int n,a[110],dp[110]={0};
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++){
		int Min=1000;
		for(int j=1;j<i;j++)
			if(i-j<=a[j])
				Min=min(Min,dp[j]);
		dp[i]=Min+1;
	}
	cout<<dp[n];
	return 0;
}