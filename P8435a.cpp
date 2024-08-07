#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int n,m,t,dfn[MAXN+10],low[MAXN+10];
vector<int> adj[MAXN+10];
stack<int> s;
vector<int> ans[MAXN+10];
int ansp;
void dfs(int u,int pre){
	dfn[u]=low[u]=++t;
	int child=0;
	s.push(u);
	for(int v:adj[u]){
		if(v==pre)	continue;
		if(!dfn[v]){
			child++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				ansp++;
				int t;
				do{t=s.top();s.pop();ans[ansp].push_back(t);}while(t!=v);
				ans[ansp].push_back(u);
			}
		}else if(v!=pre)	low[u]=min(low[u],dfn[v]);
	}
	if(pre==0&&child==0)	ans[++ansp].push_back(u);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int u=1;u<=n;u++)
		if(!dfn[u]){
			stack<int> t;
			swap(s,t);
			dfs(u,0);
		}
	cout<<ansp<<endl;
	for(int i=1;i<=ansp;i++){
		cout<<ans[i].size()<<' ';
		for(auto j:ans[i])	cout<<j<<' ';
		cout<<endl;
	}
	return 0;
}