#include<bits/stdc++.h>
using namespace std;
int n,dis[50010],_size[50010],x,y;
vector<int> adj[50010];
void dfs(int u,int fa,int depth){
	_size[u]=1;
	for(auto v:adj[u]){
		if(v!=fa){
			dfs(v,u,depth+1);
			_size[u]+=_size[v];
		}
	}
	dis[1]+=depth;
}
void cog(int u,int fa){
	for(int v:adj[u]){
		if(v!=fa){
			dis[v]=dis[u]+_size[1]-2*_size[v];
			cog(v,u);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0,0);
	cog(1,0);
	x=min_element(dis+1,dis+n+1)-dis;
	y=dis[x];
	cout<<x<<' '<<y<<endl;
	return 0;
}