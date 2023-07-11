#include<bits/stdc++.h>
using namespace std;
int n,ans=1e9,s[10],b[10];
int main(){
	int i,m;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>s[i]>>b[i];
	for(m=0;m<(1<<n);m++){
		int ts=1,tb=0;
		for(i=0;i<n;i++)
			if(m&(1<<i)){
				ts*=s[i];
				tb+=b[i];
				ans=min(ans,abs(ts-tb));
			}
	}
	cout<<ans;
	return 0;
}
