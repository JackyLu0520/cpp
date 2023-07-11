#include<bits/stdc++.h>
using namespace std;
int dp1[101],dp2[101],a[101],n,ans1=0,ans2;
int main(){
	for(int i=1;!cin.eof();i++)
		cin>>a[i];
	dp1[0]=0;
	dp2[0]=0;
	for(int i=1;i<=n;i++){
		dp1[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]<=a[j])
				dp1[i]=max(dp1[i],dp1[j]+1);
		ans1=max(ans1,dp1[i]);
		dp2[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]>a[j])
				dp2[i]=max(dp2[i],dp2[j]+1);
		ans2=max(ans2,dp2[i]);
	}
	cout<<ans1<<ans2;
	return 0;
}
