#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001,inf=2147483647;
int d[MAXN],d1[MAXN],n,m,s=1,sum=0;
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
vector<Edge> adj[MAXN],adj1[MAXN];
void dijkstra(int s,vector<Edge> adj[],int d[]){
	fill(d,d+MAXN,inf);
	fill(visited,visited+MAXN,0);
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
			if(!visited[v]&&d[u]+adj[u][j].dis<d[v]){
				d[v]=d[u]+adj[u][j].dis;
				q.push(Edge(v,d[v]));
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(Edge(v,w));
		adj1[v].push_back(Edge(u,w));
	}
	dijkstra(s,adj,d);
	dijkstra(s,adj1,d1);
	for(int i=1;i<=n;i++)
		sum+=d[i];
	for(int i=1;i<=n;i++)
		sum+=d1[i];
	cout<<sum;
	return 0;
} 
