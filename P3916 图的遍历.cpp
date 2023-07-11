#include<bits/stdc++.h>
using namespace std;
int Max,n,m;
vector<int> adj[100010];
bool visited[100010];
void dfs(int u){
	visited[u]=1;
	Max=max(Max,u);
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!visited[v])
			dfs(v);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited));
		Max=-1;
		dfs(i);
		cout<<Max<<' ';
	}
	return 0;
}
