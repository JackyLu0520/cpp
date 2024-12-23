#include<bits/stdc++.h>
#define MOD(x) (x)=((x)%mod+mod)%mod
using namespace std;
const int N=1e5+10;
int n,m,r,mod;
long long a[N];
int head[N],nxt[2*N],ver[2*N],tot=1;
void addedge(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
//Heavy-Light Decomposition - build
int size[N],son[N],fa[N],depth[N];
void dfs1(int u,int p){
    size[u]=1;
    fa[u]=p;
    depth[u]=depth[p]+1;
    int maxsize=0;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>maxsize){
            son[u]=v;
            maxsize=size[v];
        }
    }
}
int top[N],dfn[N],dfsid=0,ed[N],rk[N];
void dfs2(int u,int p){
    if(son[p]==u)   top[u]=top[p];
    else            top[u]=u;
    dfn[u]=++dfsid;
#ifdef DEBUG
    printf("->%d:dfn=%d\n",u,dfn[u]);
#endif
    rk[dfsid]=u;
    if(son[u])  dfs2(son[u],u);
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p||v==son[u]) continue;
        dfs2(v,u);
    }
    ed[u]=dfsid;
}
//Segtree
struct node{
    int l,r;
    long long sum;
    long long tag;
}t[8*N];
inline void pushup(int p){
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
    MOD(t[p].sum);
}
inline void maketag(int p,long long k){
    t[p].tag+=k;
    MOD(t[p].tag);
    t[p].sum+=(t[p].r-t[p].l+1)*k%mod;
    MOD(t[p].sum);
}
inline void pushdown(int p){
    if(t[p].tag){
        maketag(2*p,t[p].tag);
        maketag(2*p+1,t[p].tag);
        t[p].tag=0;
    }
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;t[p].tag=0;
    if(l==r){t[p].sum=a[rk[l]];MOD(t[p].sum);return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    pushup(p);
}
void add(int p,int l,int r,long long k){
    if(t[p].l>=l&&t[p].r<=r){
        maketag(p,k);
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  add(2*p,l,r,k);
    if(r>mid)   add(2*p+1,l,r,k);
    pushup(p);
}
long long query(int p,int l,int r){
    if(t[p].l>=l&&t[p].r<=r)
        return t[p].sum;
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    long long ans=0;
    if(l<=mid)  ans+=query(2*p,l,r);
    if(r>mid)   ans+=query(2*p+1,l,r);
    MOD(ans);
    return ans;
}
//Heavy-Light Decomposition - query
void addpath(int u,int v,long long k){//op1
    while(top[u]!=top[v]){
        if(depth[top[u]]>depth[top[v]]){
            add(1,dfn[top[u]],dfn[u],k);
            u=fa[top[u]];
        }else{
            add(1,dfn[top[v]],dfn[v],k);
            v=fa[top[v]];
        }
    }
    if(dfn[u]>dfn[v])   swap(u,v);
    add(1,dfn[u],dfn[v],k);
}
long long querypath(int u,int v){
    long long ans=0;
    while(top[u]!=top[v]){
        if(depth[top[u]]>depth[top[v]]){
            ans+=query(1,dfn[top[u]],dfn[u]);
            u=fa[top[u]];
        }else{
            ans+=query(1,dfn[top[v]],dfn[v]);
            v=fa[top[v]];
        }
        MOD(ans);
    }
    if(dfn[u]>dfn[v])   swap(u,v);
    ans+=query(1,dfn[u],dfn[v]);
    MOD(ans);
    return ans;
}
void addtree(int u,long long k){
    add(1,dfn[u],ed[u],k);
}
long long querytree(int u){
    return query(1,dfn[u],ed[u]);
}
//
int main(){
    scanf("%d%d%d%d",&n,&m,&r,&mod);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        addedge(u,v);addedge(v,u);
    }
    dfs1(r,0);
    dfs2(r,0);
    build(1,1,n);
#ifdef DEBUG
    for(int i=1;i<=n;i++)
        printf("%d:size=%d,son=%d,fa=%d,depth=%d,top=%d,dfn=%d,ed=%d\n",i,size[i],son[i],fa[i],depth[i],top[i],dfn[i],ed[i]);
#else
    while(m--){
        int op,u,v;long long k;
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%d%d%lld",&u,&v,&k);
                addpath(u,v,k);
                break;
            case 2:
                scanf("%d%d",&u,&v);
                printf("%lld\n",querypath(u,v));;
                break;
            case 3:
                scanf("%d%lld",&u,&k);
                addtree(u,k);
                break;
            case 4:
                scanf("%d",&u);
                printf("%lld\n",querytree(u));;
                break;
        }
    }
#endif
    return 0;
}