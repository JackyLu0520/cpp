#include<bits/stdc++.h>
using namespace std;
int v,n,a[40],Min=2147483647;
void dfs(int step){
	if(step==n){
		if(v>=0)	Min=min(Min,v);
		return;
	}
	v-=a[step];
	dfs(step+1);
	v+=a[step];
	dfs(step+1);
}
int main(){
	cin>>v>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs(1);
	cout<<Min;
	return 0;
}