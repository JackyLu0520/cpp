#include<bits/stdc++.h>
using namespace std;
int n,k,a[5010];
char b[5010][5010];
bool dfs(int l,int r,long long s){
	if(b[l][r]!=-1)	return b[l][r];
	if(s<0)	b[l][r]=0;
	else if(l==0||r==n+1)	b[l][r]=1;
	else if(dfs(l-1,r,s+a[l]))	b[l][r]=1;
	else b[l][r]=dfs(l,r+1,s+a[r]);
	return b[l][r];
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(b,-1,sizeof(b));
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		printf("%s",dfs(k-1,k+1,a[k])?"YES\n":"NO\n");
	}
	return 0;
}