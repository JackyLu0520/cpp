#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,s,depth[N],fa[N][21];
vector<int> adj[N];
void dfs(int u,int pre){
	fa[u][0]=pre;
	for(int i=1;i<=20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(auto v:adj[u]){
		if(v!=pre){
			depth[v]=depth[u]+1;
			dfs(v,u);
		}
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])	swap(x,y);
	int diff=depth[x]-depth[y];
	for(int i=0;diff;i++){
		if(diff&1)	x=fa[x][i];
		diff>>=1;
	}
	if(x==y)	return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int dis(int x,int y){
	return depth[x]+depth[y]-2*depth[lca(x,y)];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		int x,y,z,a,b,c,ans;
		cin>>x>>y>>z;
		a=lca(x,y),b=lca(x,z),c=lca(y,z);
		if(x==y&&y==z)	ans=x;
		if(x==y)		ans=z;
		if(y==z)		ans=x;
		if(x==z)		ans=y;
		cout<<ans<<' '<<dis(ans,x)+dis(ans,y)+dis(ans,z)<<endl;
	}
	return 0;
}
