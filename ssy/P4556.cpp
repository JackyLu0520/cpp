#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int head[N],nxt[2*N],ver[2*N],tot=1;
inline void addedge(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
namespace HLDLCA{
    int size[N],son[N],fa[N],depth[N];
    int top[N],dfn[N],dfsid=0;
    void dfs1(int u,int p){
        size[u]=1;son[u]=0;
        fa[u]=p;depth[u]=depth[p]+1;
        int maxsize=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p)    continue;
            dfs1(v,u);
            size[u]+=size[v];
            if(size[v]>maxsize)
                maxsize=size[v],son[u]=v;
        }
    }
    void dfs2(int u,int p){
        top[u]=(u==son[p]?top[p]:u);
        dfn[u]=++dfsid;
        if(son[u])  dfs2(son[u],u);
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p||v==son[u]) continue;
            dfs2(v,u);
        }
    }
    inline int lca(int u,int v){
        while(top[u]!=top[v])
            depth[top[u]]>depth[top[v]]?u=fa[top[u]]:v=fa[top[v]];
        return depth[u]<depth[v]?u:v;
    }
}
using HLDLCA::lca;
using HLDLCA::fa;
namespace Tree{
    struct node{
        int ls,rs;
        int key,val;
        int pri;
        int max,pos;//val
    }t[N<<8];int tot=0;
    int root[N];
    inline int newnode(int key,int val){
        int p=++tot;
        t[p].ls=t[p].rs=0;
        t[p].key=key;t[p].val=val;
        t[p].pri=rand();
        t[p].max=val;t[p].pos=key;
        return p;
    }
    inline void pushup(int p){
        t[p].max=max(t[p].val,max(t[t[p].ls].max,t[t[p].rs].max));
        if(t[p].max==t[t[p].ls].max)
            t[p].pos=t[t[p].ls].pos;
        else if(t[p].max==t[p].val)
            t[p].pos=t[p].key;
        else
            t[p].pos=t[t[p].rs].pos;
    }
    void split(int p,int key,int &L,int &R){
        if(!p){L=R=0;return;}
        if(t[p].key>key){
            R=p;
            split(t[p].ls,key,L,t[p].ls);
        }else{
            L=p;
            split(t[p].rs,key,t[p].rs,R);
        }
        pushup(p);
    }
    int merge1(int l,int r){
        if(!l||!r)  return l+r;
        if(t[l].pri>t[r].pri){
            t[l].rs=merge1(t[l].rs,r);
            pushup(l);
            return l;
        }else{
            t[r].ls=merge1(l,t[r].ls);
            pushup(r);
            return r;
        }
    }
    int merge(int p,int q){
        if(!p||!q)  return p+q;
        if(t[p].pri<t[q].pri)
            swap(p,q);
        int l,mid,r;
        split(q,t[p].key,l,r);
        split(l,t[p].key-1,l,mid);
        if(mid) t[p].val+=t[mid].val;
        t[p].ls=merge(l,t[p].ls);
        t[p].rs=merge(r,t[p].rs);
        pushup(p);
        return p;
    }
    inline void add(int &p,int key,int val){
        int L,M,R;
        split(p,key,L,R);
        split(L,key-1,L,M);
        if(!M)  M=newnode(key,val);
        else    t[M].val+=val;
        pushup(M);
        p=merge1(merge1(L,M),R);
    }
#ifdef DEBUG
    void inorder(int p){
        if(!p)  return;
        inorder(t[p].ls);
        printf("%d:%d,",t[p].key,t[p].val);
        inorder(t[p].rs);
    }
#endif
}
using Tree::t;
using Tree::merge;
using Tree::root;
using Tree::add;
int ans[N];
void dfs(int u,int p){
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs(v,u);
        root[u]=merge(root[u],root[v]);
    }
    ans[u]=t[root[u]].max==0?0:t[root[u]].pos;
#ifdef DEBUG
    printf("%d:{",u);
    Tree::inorder(root[u]);
    printf("\b}\n");
#endif
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);addedge(v,u);
    }
    HLDLCA::dfs1(1,0);
    HLDLCA::dfs2(1,0);
    for(int i=1;i<=m;i++){
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        int l=lca(u,v);
        add(root[u],k,1);
        add(root[v],k,1);
        add(root[l],k,-1);
        if(fa[l])   add(root[fa[l]],k,-1);
    }
#ifdef DEBUG
    for(int i=1;i<=n;i++){
        printf("%d:{",i);
        Tree::inorder(root[i]);
        printf("\b}\n");
    }
#endif
    t[0].max=~0x3f3f3f3f;
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}