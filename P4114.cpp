#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int head[N],nxt[2*N],ver[2*N],ew[2*N],tot=1;
inline void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N],fa[N],depth[N],son_e[N];
int top[N],dfn[N],dfsid=0,rk[N],vw[N],ev[2*N];
namespace SGT{
    struct node{
        int l,r;
        int max;
    }t[4*N];
    inline void pushup(int p){
        t[p].max=max(t[2*p].max,t[2*p+1].max);
    }
    void build(int p,int l,int r){
        t[p].l=l;t[p].r=r;
        if(l==r){t[p].max=vw[rk[l]];return;}
        int mid=(l+r)/2;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
        pushup(p);
    }
    void change(int p,int i,int k){
        if(t[p].l==t[p].r){
            t[p].max=k;
            return;
        }
        int mid=(t[p].l+t[p].r)/2;
        if(i<=mid)  change(2*p,i,k);
        else        change(2*p+1,i,k);
        pushup(p);
    }
    int query(int p,int l,int r){
        if(l>r) return -1;
        if(t[p].l>=l&&t[p].r<=r)
            return t[p].max;
        int mid=(t[p].l+t[p].r)/2;
        int ans=0;
        if(l<=mid)  ans=max(ans,query(2*p,l,r));
        if(r>mid)   ans=max(ans,query(2*p+1,l,r));
        return ans;
    }
}
namespace HLD{
    void dfs1(int u,int p){
        size[u]=1;son[u]=0;son_e[u]=0;
        fa[u]=p;depth[u]=depth[p]+1;
        int maxsize=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p)    continue;
            dfs1(v,u);
            size[u]+=size[v];
            if(maxsize<size[v])
                maxsize=size[v],son[u]=v,son_e[u]=i;;
        }
    }
    void dfs2(int u,int in_edge){
        int p=ver[in_edge^1];
        if(u==son[p])   top[u]=top[p];
        else            top[u]=u;
        dfn[u]=++dfsid;rk[dfsid]=u;
        vw[u]=ew[in_edge];
        ev[in_edge]=ev[in_edge^1]=u;
        if(son[u])
            dfs2(son[u],son_e[u]);;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p||v==son[u]) continue;
            dfs2(v,i);
        }
    }
    int query(int u,int v){
        int ans=0;
        while(top[u]!=top[v]){
            if(depth[top[u]]>depth[top[v]]){
                ans=max(ans,SGT::query(1,dfn[top[u]],dfn[u]));
                u=fa[top[u]];
            }else{
                ans=max(ans,SGT::query(1,dfn[top[v]],dfn[v]));
                v=fa[top[v]];
            }
        }
        if(depth[u]>depth[v])   swap(u,v);
        ans=max(ans,SGT::query(1,dfn[u]+1,dfn[v]));
        return ans;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    HLD::dfs1(1,0);
    HLD::dfs2(1,0);
#ifdef DEBUG
    for(int i=1;i<=n;i++)
        printf("%d:size=%d,son=%d,fa=%d,depth=%d,top=%d,dfn=%d\n",i,size[i],son[i],fa[i],depth[i],top[i],dfn[i]);
#else
    SGT::build(1,1,n);
    while(1){
        char op[10];
        scanf("%s",op);
        if(op[0]=='C'){
            int i,k;
            scanf("%d%d",&i,&k);
            SGT::change(1,dfn[ev[i]],k);
        }else if(op[0]=='Q'){
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",HLD::query(u,v));
        }else
            break;
    }
#endif
    return 0;
}