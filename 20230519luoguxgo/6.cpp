#include<bits/stdc++.h>
using namespace std;
int n,a,k;
bool b[1000010];
int pow10(int n){
	int res=1;
	for(int i=1;i<=n;i++)
		res*=10;
	return res;
}
void dfs(int step,int cnt){
	if(cnt<=k){
		b[a]=1;
	}
	if(step==n||cnt>k)
		return;
	int pow=pow10(step);
	int p=a/pow%10;
	if(p==9){a-=9*pow;dfs(step+1,cnt+1);a+=9*pow;}
	else	{a+=pow;dfs(step+1,cnt+1);a-=pow;}
	if(p==0){a+=9*pow;dfs(step+1,cnt+1);a-=9*pow;}
        else    {a-=pow;dfs(step+1,cnt+1);a+=pow;}
	dfs(step+1,cnt);
}
int main(){
	cin>>n>>a>>k;
	dfs(0,0);
	for(int i=0;i<pow10(n);i++)
		if(b[i])
			cout<<i<<endl;
	return 0;
}
