#include<bits/stdc++.h>
using namespace std;
struct E{
	int v,w;
	E(int a,int b):v(a),w(b){}
};
struct V{
	int v,dis;
	V(int a,int b):v(a),dis(b){}
	bool operator < (const V &a) const{
		return dis>a.dis;
	}
};
int n,m,dis[5010],ans,cnt=0;
bool vis[5010]={0};
vector<E> adj[5010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(E(v,w));
		adj[v].push_back(E(u,w));
	}
	memset(dis,0x7fffffff,sizeof(dis));
	dis[1]=0;
	priority_queue<V> q;
	q.push(V(1,0));
	while(q.size()){
		int u=q.top().v;
		q.pop();
		if(!vis[u]){
			vis[u]=1;
			ans+=dis[u];
			cnt++;
			for(auto e:adj[u]){
				int v=e.v,w=e.w;
				if(!vis[v]&&w<dis[v]){
					dis[v]=w;
					q.push(V(v,dis[v]));
				}
			}
		}	
	}
	if(cnt==n)	cout<<ans;
	else		cout<<"orz";
	return 0;
}