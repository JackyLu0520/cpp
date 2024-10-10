#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e4+10,L=17,M=5e4+10;
int n,m;
//edges
struct E{
    int u,v,w;
    E(){}
    E(int _u,int _v,int _w){
        u=_u,v=_v,w=_w;
    }
}e[M];
//MST
int head[N],nxt[M],ver[M],wei[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;wei[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
struct dsu{
    int fa[N];
    dsu(){}
    dsu(int cnt){for(int i=1;i<=cnt;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    bool merge(int x,int y){int xx=query(x),yy=query(y);if(xx==yy)return 0;fa[xx]=yy;return 1;}
}d;
void kruskal(){
    sort(e+1,e+m+1,[](E a,E b){return a.w>b.w;});
    for(int i=1;i<=m;i++)
        if(d.merge(e[i].u,e[i].v)){
            add(e[i].u,e[i].v,e[i].w);
            add(e[i].v,e[i].u,e[i].w);
        }
}
//LCA
bool vis[N];
int fa[N][L],minw[N][L],depth[N];
void dfs(int u,int in_edge){
    vis[u]=1;
    fa[u][0]=ver[in_edge^1];
    minw[u][0]=wei[in_edge];
    depth[u]=depth[ver[in_edge^1]]+1;
    for(int i=1;i<L;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
        minw[u][i]=min(minw[u][i-1],minw[fa[u][i-1]][i-1]);
    }
    for(int i=head[u];i;i=nxt[i])
        if((i^1)!=in_edge)
            dfs(ver[i],i);
}
int lca(int u,int v){
    if(d.query(u)!=d.query(v))  return 0x3f3f3f3f;
    int ans=0x3f3f3f3f;
    if(depth[u]<depth[v])   swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;i<L;i++){
        if(t&1) ans=min(ans,minw[u][i]),u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return ans;
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            ans=min(ans,min(minw[u][i],minw[v][i]));
            u=fa[u][i];v=fa[v][i];
        }
    return min(ans,min(minw[u][0],minw[v][0]));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        e[i]=E(u,v,w);
    }
    d=dsu(n);
    kruskal();
    memset(minw,0x3f,sizeof minw);
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            dfs(i,0);
        }
    int q;scanf("%d",&q);
    while(q--){
        int u,v;scanf("%d%d",&u,&v);
        int ans=lca(u,v);
        printf("%d\n",ans==0x3f3f3f3f?-1:ans);
    }
    return 0;
}