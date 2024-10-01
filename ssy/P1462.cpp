#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=5e4+10;
int n,m,b,f[N];
int head[N],nxt[2*M],ver[2*M],e[2*M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
bool check(int x){
    if(x<f[1])  return 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    int dis[N],vis[N];
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;q.push(make_pair(0,1));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(f[v]<=x&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v])
                    q.push(make_pair(dis[v],v));
            }
        }
    }
    /*printf("%d\n",x);
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    printf("\n");*/
    return dis[n]<=b;
}
signed main(){
    int l=0,r=0;
    scanf("%lld%lld%lld",&n,&m,&b);
    for(int i=1;i<=n;i++){
        scanf("%lld",&f[i]);
        r=max(r,f[i]);
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    if(!check(r)){printf("AFK");return 0;}
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))  r=mid;
        else            l=mid+1;
    }
    printf("%lld",l);
    return 0;
}