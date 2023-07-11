#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,q,depth[N],fa[N][21];
vector<int> adj[N];
void dfs(int u,int pre){
	fa[u][0]=pre;
	for(int i=1;i<=20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(auto v:adj[u]){
		if(v!=pre){
			depth[v]=depth[u]+1;
			dfs(v,u);
		}
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])	swap(x,y);
	int diff=depth[x]-depth[y];
	for(int i=0;diff;i++){
		if(diff&1)	x=fa[x][i];
		diff>>=1;
	}
	if(x==y)	return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int dis(int u,int v){
	return depth[u]+depth[v]-2*depth[lca(u,v)];
}
int main(){
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++){
		int a,b,c,d,x,y;
		cin>>a>>b>>c>>d;
		x=lca(a,b),y=lca(c,d);
		if(dis(c,d)==dis(x,c)+dis(x,d)||dis(a,b)==dis(y,a)+dis(y,b))
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}
