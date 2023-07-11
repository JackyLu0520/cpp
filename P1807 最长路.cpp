#include<bits/stdc++.h> 
using namespace std;
const int MAXN=1501,INF=0x3f3f3f3f;
struct Edge{
	int v,dis;
	Edge(int _v,int _dis){
		v=_v,dis=_dis;
	}
};
vector<Edge> adj[MAXN];
int n,m,dp[MAXN];
bool visited[MAXN];
int DP(int u){
	if(visited[u])	return dp[u];
	visited[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].v,dis=adj[u][i].dis;
		dp[u]=max(dp[u],DP(v)+dis);
	}
	return dp[u];
}
int main(){
	cin>>n>>m;
	fill(dp,dp+MAXN,-INF);
	dp[n]=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(Edge(v,w));
	}
	int ans=DP(1);
	if(visited[n])	cout<<ans;
	else	cout<<-1;
	return 0;
}
