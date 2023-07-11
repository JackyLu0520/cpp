#include<bits/stdc++.h>
using namespace std;
int n,m,t,dfn[100010],low[100010];
vector<int> adj[100010];
void dfs(int u,int pre){
	dfn[u]=low[u]=++t;
	for(int v:adj[u]){
		if(v==pre)	continue;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		cout<<dfn[i]<<' '<<low[i]<<endl;
	}
	return 0;
}