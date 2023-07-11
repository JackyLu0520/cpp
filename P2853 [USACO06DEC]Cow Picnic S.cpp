#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[110],t,num=0,visited[1010];
vector<int> adj[1010];
bool f;
void dfs(int u,int v){
	visited[u]=1;
	if(u==v){
		f=1;
		return;
	}
	for(int i=0;i<adj[u].size();i++)
		if(!visited[adj[u][i]])
			dfs(adj[u][i],v);
}
int main(){
	int i,j;
	cin>>k>>n>>m;
	for(i=1;i<=k;i++)
		cin>>a[i];
	for(i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=k;i++){
			f=0;
			memset(visited,0,sizeof(visited));
			dfs(a[j],i);
			if(!f)	break;
		}
		if(f)	num++;
	}
	cout<<num;
	return 0;
}
