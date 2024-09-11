#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10,MAXM=5e4+10;
int n,m,q;
bool vis[MAXN][MAXN];

int head[MAXN],nxt[MAXM],ver[MAXM],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}

int dfn[MAXN],low[MAXN],bridge[MAXM],dfsid;
void tarjan(int u,int in_edge){
    dfn[u]=low[u]=++dfsid;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u])
                bridge[i]=bridge[i^1]=1;
        }else if(i!=(in_edge^1))
            low[u]=min(low[u],dfn[v]);
    }
}

int c[MAXN],dccid;
void dfs(int u){
    c[u]=dccid;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(c[v]||bridge[i]) continue;
        dfs(v);
    }
}

int hc[MAXN],nc[MAXM],vc[MAXM],tc=1;
void addc(int u,int v){
    vc[++tc]=v;nc[tc]=hc[u];hc[u]=tc;
}

int fa[MAXN][21],depth[MAXN];
void lca_prework(int u,int pre){
    depth[u]=depth[pre]+1;fa[u][0]=pre;
    for(int i=1;i<=20;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=hc[u];i;i=nc[i]){
        int v=vc[i];
        if(v!=pre)
            lca_prework(v,u);
    }
}
int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=0;diff;i++){
        if(diff&1)  u=fa[u][i];
        diff>>=1;
    }
    if(u==v)    return u;
    for(int i=20;i>=0&&u!=v;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}

void printbin(int n){
    if(!n){printf("0");return;}
    if(n==1){printf("1");return;}
    printbin(n>>1);
    printf("%d",n&1);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(!vis[u][v]&&!vis[v][u]){
            add(u,v);
            add(v,u);
            vis[u][v]=1;
            vis[v][u]=1;
        }
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i,0);
    
    for(int i=1;i<=n;i++)
        if(!c[i]){
            dccid++;
            dfs(i);
        }
    
    for(int i=2;i<=tot;i+=2){
        int u=ver[i^1],v=ver[i];
        if(c[u]==c[v])  continue;
        addc(c[u],c[v]);addc(c[v],c[u]);
    }

    scanf("%d",&q);
    lca_prework(1,0);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        int ans=depth[c[u]]+depth[c[v]]-2*depth[lca(c[u],c[v])]+1;
        printbin(ans);
        //printf("%d",ans);
        printf("\n");
    }
    return 0;
}