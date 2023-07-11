#include<bits/stdc++.h>
using namespace std;
int n,root,fa[100010];
vector<int> g[100010];
void solve(int r){
	for(int i=0;i<g[r].size();i++)
		if(g[r][i]!=fa[r]){
			fa[g[r][i]]=r;
			solve(g[r][i]);
		}
}
int main(){
	cin>>n>>root;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fa[root]=0;
	solve(root);
	for(int i=1;i<=n;i++)
		cout<<fa[i]<<' ';
	return 0;
}