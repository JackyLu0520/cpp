#include<bits/stdc++.h>
using namespace std;
int n,k,a[10010],ans=2147483647;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-k+1;i++){
		int Min=100000,Max=0;
		for(int j=i;j<=i+k-1;j++){
			Min=min(Min,a[j]);
			Max=max(Max,a[j]);
		}
		for(int j=Min;j<=Max;j++){
			int s=0;
			for(int l=i;l<=i+k-1;l++)
				s+=abs(j-a[l]);
			ans=min(ans,s);
			//cout<<s<<' '<<i<<' '<<j<<endl;
		}
	}
	cout<<ans;
	return 0;
}