#include<bits/stdc++.h>
using namespace std;
int n,ans[2],cur=0,a[1000010];
unordered_map<int,int> b;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=0;
	}
	for(int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(auto x:b){
		if(x.second==1){
			ans[cur]=x.first;
			cur++;
		}
	}
	cout<<abs(ans[0]+ans[1])<<endl;
	return 0;
}