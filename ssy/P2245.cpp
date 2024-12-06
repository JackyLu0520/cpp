#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=3e5+10,L=20;
int n,m,q;
struct E{
    int u,v,w;
    E(){}
    E(int _u,int _v,int _w){
        u=_u;v=_v;w=_w;
    }
    inline bool operator<(const E& a)const{
        return w<a.w;
    }
}e[M];
struct dsu{
    int fa[2*N],tot=0;
    int newnode(){tot++;fa[tot]=tot;return tot;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    int merge(int x,int y){
        int xx=query(x),yy=query(y);
        if(xx==yy)  return xx;
        return fa[xx]=fa[yy]=newnode();
    }
}d;
int head[2*N],vw[2*N],nxt[4*M],ver[4*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
void kruskal(){
    for(int i=1;i<=n;i++)
        d.newnode();
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int uu=d.query(e[i].u),vv=d.query(e[i].v);
        if(uu!=vv){
            int p=d.merge(e[i].u,e[i].v);
            add(p,uu);add(p,vv);
            vw[p]=e[i].w;
        }
    }
}
int fa[2*N][L],depth[2*N];
void dfs(int u,int p){
    fa[u][0]=p;depth[u]=depth[p]+1;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
#ifdef DEBUG
    printf("fa[%d]:",u);
    for(int i=0;i<L;i++)
        printf("%d ",fa[u][i]);
    printf("\n");
#endif
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(depth[u]<depth[v])
        swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1) u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    kruskal();
    for(int i=1;i<=2*n;i++)
        if(d.query(i)==i)
            dfs(i,0);
    scanf("%d",&q);
    while(q--){
        int u,v;scanf("%d%d",&u,&v);
        int f=lca(u,v);
#ifdef DEBUG
        printf("%d ",f);
#endif
        if(vw[f]==0)
            printf("impossible\n");
        else
            printf("%d\n",vw[f]);
    }
    return 0;
}