#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=22,M=1e5+10,K=1e5+10;
int n,m;
int head[N],nxt[2*N],ver[2*N],etot=1;
void add(int u,int v){
    ver[++etot]=v;nxt[etot]=head[u];head[u]=etot;
}
namespace LCA{
    int fa[N][L],depth[N];
    void dfs(int u,int p){
        fa[u][0]=p;
        depth[u]=depth[p]+1;
        for(int i=1;i<L;i++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p)    continue;
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
}
using LCA::fa;
namespace SegTree{
    struct node{
        int max;
        int ls,rs;
    }t[4*M*L];int tot;
    int root[N];
    inline int newnode(){
        int p=++tot;
        t[p].max=0;
        t[p].ls=t[p].rs=0;
        return p;
    }
    inline void pushup(int p){
        t[p].max=max(t[t[p].ls].max,t[t[p].rs].max);
    }
    void add(int &p,int i,int k,int l,int r){
        if(!p)  p=newnode();
        if(l==r){
            t[p].max+=k;
            return;
        }
        int mid=(l+r)/2;
        if(i<=mid)  add(t[p].ls,i,k,l,mid);
        else        add(t[p].rs,i,k,mid+1,r);
        pushup(p);
    }
    void merge(int &p,int q,int l,int r){//p+=q
        if(!p||!q){
            p=p|q;return;
        }
        if(l==r){
            t[p].max+=t[q].max;
            return;
        }
        int mid=(l+r)/2;
        merge(t[p].ls,t[q].ls,l,mid);
        merge(t[p].rs,t[q].rs,mid+1,r);
        pushup(p);
    }
    int query(int p,int l,int r){
        if(l==r)    return l;
        int mid=(l+r)/2;
        if(t[p].max==t[t[p].ls].max)    return query(t[p].ls,l,mid);
        else                            return query(t[p].rs,mid+1,r);
    }
}
using SegTree::root;
void dfs(int u,int p){
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v!=p)    continue;
        dfs(v,u);
        SegTree::merge(root[u],root[v],1,K);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    LCA::dfs(1,0);
    for(int i=1;i<=m;i++){
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        int lca=LCA::lca(u,v);
        SegTree::add(root[u],k,1,1,K);
        SegTree::add(root[v],k,1,1,K);
        SegTree::add(root[lca],k,-1,1,K);
        SegTree::add(root[fa[lca][0]],k,-1,1,K);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",SegTree::query(root[i],1,K));
    return 0;
}