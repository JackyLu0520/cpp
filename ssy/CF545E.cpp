#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,M=3e5+10;
int n,m,s;
int head[N],nxt[2*M],ver[2*M],tot=1;
long long ew[2*M];
void add(int u,int v,long long w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
long long dis[N];
int pre[N],vis[N],preedge[N];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>q;
long long ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;long long w;scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    scanf("%d",&s);
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;q.emplace(0,s);
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(dis[v]>=dis[u]+w){
                dis[v]=dis[u]+w;
                pre[v]=u;
                preedge[v]=i;
                q.emplace(dis[v],v);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(preedge[i])
            ans+=1ll*ew[preedge[i]];
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)
        if(preedge[i])
            printf("%d ",preedge[i]>>1);
    return 0;
}