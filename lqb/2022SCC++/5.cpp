#include<bits/stdc++.h>
using namespace std;
const int MAXN=110,inf=2147483647;
int d[MAXN],n,m;
bool visited[MAXN];
struct Edge{
	int v,dis;
	Edge(int _v,int _dis){
		v=_v;
		dis=_dis;
	}
	bool operator < (const Edge &a) const{
		return dis>a.dis;
	}
};
vector<Edge> adj[MAXN];
void dijkstra(int s){
	fill(d,d+MAXN,inf);
	d[s]=0;
	priority_queue<Edge> q;
	q.push(Edge(s,0));
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(visited[u])	continue;
		visited[u]=1;
		for(int j=0;j<adj[u].size();j++){
			int v=adj[u][j].v;
			if(!visited[v]&&d[u]+1<d[v]){
				d[v]=d[u]+1;
				q.push(Edge(v,d[v]));
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(Edge(v,1));
		adj[v].push_back(Edge(u,1));
	}
	dijkstra(n);
	for(int i=1;i<=n-1;i++)
		if(d[i]==inf)	cout<<-1<<' ';
		else cout<<d[i]<<' ';
	return 0;
} 
