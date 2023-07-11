#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001,inf=2147483647;
int d[MAXN],n,m,s;
bool inq[MAXN];
struct Edge{
	int v,dis;
	Edge(int _v,int _dis){
		v=_v;
		dis=_dis;
	}
};
vector<Edge> adj[MAXN];
void SPFA(int s){
	memset(inq,0,sizeof(inq));
	fill(d,d+MAXN,inf);
	d[s]=0;
	inq[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].v,dis=adj[u][i].dis;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				} 
			}
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
	SPFA(s);
	for(int i=1;i<=n;i++)
		cout<<d[i]<<' ';
	return 0;
} 
