#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,K=13,M=5e4+10;
int n,m,k,s,t;
int head[N*K],nxt[4*K*M+K],ver[4*K*M+K],ew[4*K*M+K],tot=1;
inline void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N*K],vis[N*K];
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
>q;
void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.emplace(0,s);dis[s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.emplace(dis[v],v);
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        for(int j=0;j<=k;j++){
            add(u+j*n,v+j*n,w);
            add(v+j*n,u+j*n,w);
        }
        for(int j=1;j<=k;j++){
            add(u+(j-1)*n,v+j*n,0);
            add(v+(j-1)*n,u+j*n,0);
        }
    }
    for(int i=1;i<=k;i++)
        add(t+(i-1)*n,t+i*n,0);
    dijkstra();
    printf("%d\n",dis[t+k*n]);
    return 0;
}