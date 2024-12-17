#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=5e5+10,L=20;
int n,m,k;
int head[N],nxt[M],ver[M],tot=1;
long long ew[M];
void add(int u,int v,long long w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int a[N];
long long dis[N];
bool vis[N];
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
>q;
long long dijkstra(int p,bool c){
    //clear
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while(!q.empty())q.pop();
    //
    for(int i=1;i<=k;i++)
        if(((a[i]>>p)&1)==c){
            q.emplace(0,a[i]);
            dis[a[i]]=0;
        }
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];long long w=ew[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.emplace(dis[v],v);
            }
        }
    }
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=k;i++)
        if(((a[i]>>p)&1)!=c)
            ans=min(ans,dis[a[i]]);
    return ans;
}
int main(){
    int _;scanf("%d",&_);
    while(_--){
        //clear
        memset(head,0,sizeof(head));
        tot=1;
        //
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=m;i++){
            int u,v;long long w;
            scanf("%d%d%lld",&u,&v,&w);
            add(u,v,w);
        }
        for(int i=1;i<=k;i++)
            scanf("%d",&a[i]);
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<=L;i++)
            ans=min(ans,min(dijkstra(i,0),dijkstra(i,1)));
        printf("%lld\n",ans);
    }
    return 0;
}