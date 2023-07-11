#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,a[200010],fa[200010],depth[200010];
vector<int> adj[200010];
void dfs(int root){
	for(int u:adj[root])
		if(u!=fa[root]){
			fa[u]=root;
			depth[u]=depth[root]+1;
			dfs(u);
		}
}
int main(){
	cin>>n>>k>>x>>y;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fa[1]=1;
	depth[1]=0;
	dfs(1);
	
}