#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=1e5+10;
int n,m,ans=0x3f3f3f3f;
int head[N],nxt[2*M],ver[2*M],e[2*M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[2][N];
void Dijkstra(int s,bool f){
    bool vis[N];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    memset(dis[f],0x3f,sizeof(dis[f]));
    memset(vis,0,sizeof(vis));
    dis[f][s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[f][v]>dis[f][u]+w){
                dis[f][v]=dis[f][u]+w;
                q.push(make_pair(dis[f][v],v));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    Dijkstra(1,0);Dijkstra(n,1);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[0][u]+dis[1][v]>dis[0][v]+dis[1][u])
                continue;
            if(dis[0][u]+w+dis[1][v]!=dis[0][n])
                ans=min(ans,dis[0][u]+w+dis[1][v]);
        }
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[0][u]+dis[1][v]>dis[0][v]+dis[1][u])
                continue;
            if(dis[0][u]+w+dis[1][v]==dis[0][n])
                ans=min(ans,dis[0][n]+2*w);
        }
    printf("%d",ans);
    return 0;
}