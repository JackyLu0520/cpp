#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],maxa;
long long ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		maxa=max(maxa,a[i]);
	}
	for(int i=maxa;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>=i)
				cnt++;
			else{
				ans=max(ans,cnt*1LL*i);
				cnt=0;
			}
		}
		ans=max(ans,cnt*1LL*i);
	}
	cout<<ans;
	return 0;
}
