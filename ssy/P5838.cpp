#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=20;
int n,m,t[N];
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N],fa[N],depth[N];
int top[N],dfn[N],dfsid=0,rk[N];
namespace PSGT{
    struct node{
        int ls,rs;
        int val;//leaf
    }t[N*L];int tot=-1;
    int root[N]={0};
    void build(int &p,int l,int r){
        if(!p)  p=++tot;
        if(l==r){t[p].val=0;return;}
        int mid=(l+r)/2;
        build(t[p].ls,l,mid);
        build(t[p].rs,mid+1,r);
    }
    void add(int &p,int q,int l,int r,int i,int k){//q---val[i]+=k-->p
        if(!p)  p=++tot;
        if(l==r){
            t[p].val=t[q].val+k;
            return;
        }
        int mid=(l+r)/2;
        if(i<=mid)  t[p].rs=t[q].rs,add(t[p].ls,t[q].ls,l,mid,i,k);
        else        t[p].ls=t[q].ls,add(t[p].rs,t[q].rs,mid+1,r,i,k);
    }
    int query(int p,int l,int r,int i){
        if(l==r)    return t[p].val;
        int mid=(l+r)/2;
        if(i<=mid)  return query(t[p].ls,l,mid,i);
        else        return query(t[p].rs,mid+1,r,i);
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
            if(size[v]>maxsize)
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
    bool query(int u,int v,int k){
        while(top[u]!=top[v]){
            if(depth[top[u]]>depth[top[v]]){
                if(PSGT::query(PSGT::root[dfn[u]],1,n,k)
                    >PSGT::query(PSGT::root[dfn[top[u]]-1],1,n,k))
                    return 1;
                u=fa[top[u]];
            }else{
                if(PSGT::query(PSGT::root[dfn[v]],1,n,k)
                    >PSGT::query(PSGT::root[dfn[top[v]]-1],1,n,k))
                    return 1;
                v=fa[top[v]];
            }
        }
        if(dfn[u]>dfn[v])   swap(u,v);
        if(PSGT::query(PSGT::root[dfn[u]-1],1,n,k)
            <PSGT::query(PSGT::root[dfn[v]],1,n,k))
            return 1;
        return 0;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    HLD::dfs1(1,0);
    HLD::dfs2(1,0);
#ifdef DEBUG
    for(int i=1;i<=n;i++)
        printf("%d:size=%d,son=%d,fa=%d,depth=%d,top=%d,dfn=%d\n",i,size[i],son[i],fa[i],depth[i],top[i],dfn[i]);
#else
    PSGT::build(PSGT::root[0],1,n);
    for(int i=1;i<=n;i++)
        PSGT::add(PSGT::root[i],PSGT::root[i-1],1,n,t[rk[i]],1);
    while(m--){
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        printf("%d",HLD::query(u,v,k));
    }
#endif
    return 0;
}