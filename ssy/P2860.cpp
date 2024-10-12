#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e3+10,M=1e4+10;
int n,m;
int head[N],nxt[2*M],ver[2*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dfn[N],low[N],dfsid;
bool bridge[2*M];
void tarjan(int u,int in_edge){
    dfn[u]=low[u]=++dfsid;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v])
                bridge[i]=bridge[i^1]=1;
        }else if(i!=(in_edge^1))
            low[u]=min(low[u],dfn[v]);
    }
}
int c[N],dccid;
void dfs(int u,int color){
    c[u]=color;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!c[v]&&!bridge[i])
            dfs(v,color);
    }
}
int deg[N],cnt=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    tarjan(1,0);
    for(int i=1;i<=n;i++)
        if(!c[i])
            dfs(i,++dccid);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(c[u]!=c[v])
                deg[c[u]]++;
        }
    for(int i=1;i<=dccid;i++)
        if(deg[i]==1)
            cnt++;
    printf("%d",(cnt+1)/2);
    return 0;
}