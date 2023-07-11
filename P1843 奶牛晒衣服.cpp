#include<bits/stdc++.h>
using namespace std;
int n,a,b,w[500010];
bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		int t=w[i]-a*x;
		if(t<=0)	continue;
		sum+=ceil(t*1.0/b);
	}
	return sum<=x;
}
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	int l=1,r=500000,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else
			l=mid+1;
	}
	cout<<ans;
	return 0;
}