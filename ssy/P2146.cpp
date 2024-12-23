#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
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
    int sum;
    int tag;
}t[8*N];
inline void pushup(int p){
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
}
inline void maketag(int p,int k){
    t[p].tag=k;
    t[p].sum=(t[p].r-t[p].l+1)*k;
}
inline void pushdown(int p){
    if(t[p].tag!=-1){
        maketag(2*p,t[p].tag);
        maketag(2*p+1,t[p].tag);
        t[p].tag=-1;
    }
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;t[p].tag=-1;
    if(l==r){t[p].sum=0;return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    pushup(p);
}
void overwrite(int p,int l,int r,int k){
    if(t[p].l>=l&&t[p].r<=r){
        maketag(p,k);
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  overwrite(2*p,l,r,k);
    if(r>mid)   overwrite(2*p+1,l,r,k);
    pushup(p);
}
int query(int p,int l,int r){
    if(t[p].l>=l&&t[p].r<=r)
        return t[p].sum;
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    int ans=0;
    if(l<=mid)  ans+=query(2*p,l,r);
    if(r>mid)   ans+=query(2*p+1,l,r);
    return ans;
}
//Heavy-Light Decomposition - query
void overwritepath(int u,int k){//op1
    while(u){
        overwrite(1,dfn[top[u]],dfn[u],k);
        u=fa[top[u]];
    }
}
int querypath(int u){
    int ans=0;
    while(u){
        ans+=dfn[u]-dfn[top[u]]+1-query(1,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
    return ans;
}
void overwritetree(int u,int k){
    overwrite(1,dfn[u],ed[u],k);
}
int querytree(int u){
    return query(1,dfn[u],ed[u]);
}
//
int main(){
    scanf("%d",&n);
    for(int u=2;u<=n;u++){
        int v;scanf("%d",&v);v++;
        addedge(u,v);addedge(v,u);
    }
    dfs1(1,0);
    dfs2(1,0);
    build(1,1,n);
#ifdef DEBUG
    for(int i=1;i<=n;i++)
        printf("%d:size=%d,son=%d,fa=%d,depth=%d,top=%d,dfn=%d,ed=%d\n",i,size[i],son[i],fa[i],depth[i],top[i],dfn[i],ed[i]);
#else
    scanf("%d",&m);
    while(m--){
        char op[15];int x;
        scanf("%s%d",op,&x);x++;
        if(op[0]=='i'){
            printf("%d\n",querypath(x));
            overwritepath(x,1);
        }else{
            printf("%d\n",querytree(x));
            overwritetree(x,0);
        }
    }
#endif
    return 0;
}