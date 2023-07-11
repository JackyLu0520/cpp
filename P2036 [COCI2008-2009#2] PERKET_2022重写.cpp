#include<bits/stdc++.h>
using namespace std;
int n,s[15],b[15],ts=1,tb=0,Min=0x7fffffff;
void dfs(int step){
	if(step==n+1){
		Min=min(Min,abs(ts-tb));
		return;
	}
	ts*=s[step];
	tb+=b[step];
	dfs(step+1);
	ts/=s[step];
	tb-=b[step];
	dfs(step+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>b[i];
	dfs(1);
	cout<<Min;
	return 0;
}