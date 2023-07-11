#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[100010];
bool visited[100010],inq[100010];
void dfs(int u){
	visited[u]=1;
	cout<<u<<' ';
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!visited[v])
			dfs(v);
	}
}
void bfs(int s){
	queue<int> q;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cout<<u<<' ';
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(!inq[v]){
				q.push(v);
				inq[v]=1;
			}
		}
	} 
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		sort(adj[i].begin(),adj[i].end());
	dfs(1);
	cout<<endl;
	bfs(1);
	return 0;
} 
