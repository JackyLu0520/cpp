#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4;
int n,m,t,ans,dfn[MAXN+10],low[MAXN+10];
vector<int> adj[MAXN+10];
void tarjan(int u,int pre){
	dfn[u]=low[u]=++t;
	for(int v:adj[u]){
		if(v==pre)	continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v])
				ans++;
		}else   low[u]=min(low[u],dfn[v]);
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
		if(!dfn[u])	tarjan(u,u);
	}
	cout<<ans<<endl;
	return 0;
}