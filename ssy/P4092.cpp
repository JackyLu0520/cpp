#include<bits/stdc++.h>
#define lowbit(x) (x)&(-(x))
using namespace std;
const int N=1e5+10;
int n,q;
int head[N],nxt[2*N],ver[2*N],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N],fa[N],depth[N];
int top[N],dfn[N],dfsid=0,rk[N];
namespace BIT{
    int c[N]={0};
    void sign(int p){
        for(int i=p;i<=n;i+=lowbit(i))
            c[i]=max(c[i],p);
    }
    int query(int i){
        for(;i;i-=lowbit(i))
            if(c[i])
                return c[i];
    }
}
namespace HLD{
    void dfs1(int u,int p){
        size[u]=1;son[u]=0;
        fa[u]=p;depth[u]=depth[p]+1;
        int maxsize=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p)    continue;
            dfs1(v,u);
            size[u]+=size[v];
            if(maxsize<size[v])
                maxsize=size[v],son[u]=v;
        }
    }
    void dfs2(int u,int p){
        if(u==son[p])   top[u]=top[p];
        else            top[u]=u;
        dfn[u]=++dfsid;rk[dfsid]=u;
        if(son[u])
            dfs2(son[u],u);
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p||v==son[u]) continue;
            dfs2(v,u);
        }
    }
    inline void sign(int u){
        BIT::sign(dfn[u]);
    }
    int query(int u){
        while(u){
            int t=BIT::query(dfn[u]);
            if(t>=dfn[top[u]])   return rk[t];
            u=fa[top[u]];
        }
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    HLD::dfs1(1,0);
    HLD::dfs2(1,0);
    BIT::sign(1);
    while(q--){
        char op;int u;
        scanf(" %c%d",&op,&u);
        if(op=='C'){
            HLD::sign(u);
        }else{
            printf("%d\n",HLD::query(u));
        }
    }
    return 0;
}