#include<bits/stdc++.h>
using namespace std;
const int MAXN=10001,inf=2147483647;
int d[MAXN],n,m,s;
bool visited[MAXN];
struct Edge{
	int v,dis;
	Edge(int _v,int _dis){
		v=_v;
		dis=_dis;
	}
};
vector<Edge> adj[MAXN];
void dijkstra(int s){
	fill(d,d+MAXN,inf);
	d[s]=0;
	for(int i=1;i<=n;i++){
		int u=-1,MIN=inf;
		for(int j=1;j<=n;j++){
			if(!visited[j]&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)	return;
		visited[u]=1;
		for(int j=0;j<adj[u].size();j++){
			int v=adj[u][j].v;
			if(!visited[v]&&d[u]+adj[u][j].dis<d[v])
				d[v]=d[u]+adj[u][j].dis;
		}
	}
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(Edge(v,w));
	}
	dijkstra(s);
	for(int i=1;i<=n;i++)
		cout<<d[i]<<' ';
	return 0;
} 
