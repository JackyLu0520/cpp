#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4;
int n,m,k,s,t,dis[MAXN*11+10];
bool vis[MAXN*11+10];
struct E{int v,w;E(){}E(int V,int W){v=V;w=W;}};
struct V{int u,dis;V(){}V(int U,int DIS){u=U;dis=DIS;}bool operator < (const V& a) const {return dis>a.dis;}};
vector<E> adj[MAXN*11+10];
void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<V> q;
    q.push(V(s,0));
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(auto e:adj[u])
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                q.push(V(e.v,dis[e.v]));
            }
    }
}
int main(){
    cin>>n>>m>>k>>s>>t;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(E(v,w));
        adj[v].push_back(E(u,w));
        for(int j=1;j<=k;j++){
            adj[u+(j-1)*n].push_back(E(v+j*n,0));
            adj[u+(j-1)*n].push_back(E(v+j*n,0));
            adj[u+j*n].push_back(E(v+j*n,w));
            adj[v+j*n].push_back(E(u+j*n,w));
        }
    }
    for(int i=1;i<=k;i++)
        adj[t+(i-1)*n].push_back(E(t+i*n,0));
    dijkstra();
    cout<<dis[t+k*n];
    return 0;
}