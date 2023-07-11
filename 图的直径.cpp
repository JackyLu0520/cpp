#include<bits/stdc++.h>
using namespace std;
int vt,d[101],pre[101];
vector<int> adj[101];
void dfs(int u,int fa,bool m){
	if(d[u]>d[vt])	vt=u;
	for(auto v:adj[u])
		if(v!=fa){
			d[v]=d[u]+1;
			if(m)	pre[v]=u;
			dfs(v,u,m);
		}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0,0);
	d[vt]=0;
	dfs(vt,0,1);
	cout<<d[vt]<<endl;
	while(vt){
		cout<<vt<<' ';
		vt=pre[vt];
	}
	return 0;
}