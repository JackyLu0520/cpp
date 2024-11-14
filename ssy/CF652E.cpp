#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,M=3e5+10;
int n,m,a,b;
int head[N],nxt[2*M],ver[2*M],ew[2*M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dfn[N],low[N],dfsid=0;
bool bridge[2*M];
void tarjan(int u,int in_edge){
    dfn[u]=low[u]=++dfsid;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[v],low[u]);
            if(low[v]>dfn[u])
                bridge[i]=bridge[i^1]=1;
        }else if((i^1)!=in_edge)
            low[u]=min(low[u],dfn[v]);
    }
}
int c[N],dccid;
void dfs1(int u,int color){
    c[u]=color;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(c[v]||bridge[i]) continue;
        dfs1(v,color);
    }
}
int hc[N],nc[2*M],vc[2*M],ewc[2*M],tc=1;
void addc(int u,int v,int w){
    vc[++tc]=v;ewc[tc]=w;nc[tc]=hc[u];hc[u]=tc;
}
int vwc[N];
int dis[N];
void dfs2(int u,int p,int pw){
    dis[u]=dis[p]+pw+vwc[u];
    for(int i=hc[u];i;i=nc[i]){
        int v=vc[i],w=ewc[i];
        if(v!=p)
            dfs2(v,u,w);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    scanf("%d%d",&a,&b);
    tarjan(1,0);
    for(int i=1;i<=n;i++)
        if(!c[i])
            dfs1(i,++dccid);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=ew[i];
            if(c[u]==c[v])
                vwc[c[u]]+=w;
            else
                addc(c[u],c[v],w);
        }
    dfs2(c[a],0,0);
    printf(dis[c[b]]?"YES":"NO");
    return 0;
}