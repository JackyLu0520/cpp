#include<bits/stdc++.h>
using namespace std;
int n,m,t,dfn[100010];
vector<int> adj[100010];
void dfs(int u){
	dfn[u]=++t;
	for(int v:adj[u]){
		if(!dfn[v]){
			dfs(v);
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
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<dfn[i]<<endl;
	}
	return 0;
}