#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,s,depth[N],fa[N];
vector<int> adj[N];
void dfs(int u,int pre){
	fa[u]=pre;
	for(auto v:adj[u]){
		if(v!=pre){
			depth[v]=depth[u]+1;
			dfs(v,u);
		}
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])	swap(x,y);
	while(depth[x]>depth[y])	x=fa[x];
	if(x==y)	return x;
	while(fa[x]!=fa[y]){
		x=fa[x];
		y=fa[y];
	}
	return fa[x];
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(s,0);
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
	return 0;
}
