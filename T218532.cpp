#include<bits/stdc++.h>
using namespace std;
const int MAXN=200001;
int n,q;
long long a[MAXN],s[MAXN];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		int opt,l,r,x;
		cin>>opt>>l>>r;
		if(opt){
			cout<<s[r]-s[l-1]<<endl;
		}
		else{
			cin>>x;
			for(int i=l;i<=n;i++){
				if(i<=r)	s[i]+=(i-l+1)*x;
				else	s[i]+=(r-l+1)*x;
			}
		}
	}
	return 0;
}
