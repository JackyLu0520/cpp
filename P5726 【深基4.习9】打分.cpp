#include<bits/stdc++.h>
using namespace std;
int n,Min=11,Max=0,sum=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		Min=min(Min,t);
		Max=max(Max,t);
		sum+=t;
	}
	cout<<fixed<<setprecision(2)<<(sum-Min-Max)*1.0/(n-2);
	return 0;
}