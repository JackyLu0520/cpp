#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans,dfn[100010],low[100010];
vector<int> adj[100010];
bool isCutVertex[100010];
void dfs(int u,int pre){
	dfn[u]=low[u]=++t;
	int child=0;
	for(int v:adj[u]){
		if(v==pre)	continue;
		if(!dfn[v]){
			child++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(u!=pre&&dfn[u]<=low[v]&&!isCutVertex[u]){
				ans++;
				isCutVertex[u]=1;
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(u==pre&&child>1&&!isCutVertex[u]){
		ans++;
		isCutVertex[u]=1;
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
	for(int u=1;u<=n;u++){
		if(!dfn[u])	dfs(u,u);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(isCutVertex[i])	cout<<i<<' ';
	}
	return 0;
}