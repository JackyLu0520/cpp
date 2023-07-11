#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
vector<int> adj[MAXN];
int n,x,y,k,a[MAXN],fa[MAXN],t=0;
bool vis[MAXN]={0};
void dfs(int u,int pre){
	fa[u]=pre;
	for(auto v:adj[u])
		if(v!=pre){
			dfs(v,u);
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
	dfs(x,0);
	while(x!=y){
		vis[y]=1;
		t++;
		y=fa[y];
	}
	vis[x]=1;
	for(int i=1;i<=k;i++){
		if(vis[a[i]])	continue;
		while(!vis[a[i]]){
			vis[a[i]]=1;
			t+=2;
			a[i]=fa[a[i]];
		}
	}
	cout<<t;
	return 0;
}