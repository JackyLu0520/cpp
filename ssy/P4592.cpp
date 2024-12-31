#include<bits/stdc++.h>
#define DEBUG
using namespace std;
const int N=1e6+10,L=30;
int n,q;
int v[N];
int head[N],nxt[2*N],ver[2*N],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N],fa[N],depth[N];
int top[N],dfn[N],dfsid=0,rk[N],ed[N];
namespace P01Trie{
    int trie[N*(L+1)][2],cnt[N*(L+1)];
    int root[N],tot=0;
    inline void pushup(int p){
        cnt[p]=cnt[trie[p][0]]+cnt[trie[p][1]];
    }
    void insert(int &p,int q,int x,int pos){
        if(!p)  p=++tot;
        if(pos==-1){
            cnt[p]=cnt[q]+1;
            return;
        }
        int c=(x>>pos)&1;
        trie[p][c^1]=trie[q][c^1];
        insert(trie[p][c],trie[q][c],x,pos-1);
        pushup(p);
    }
    int query(int p,int q,int x,int pos,int val){
        if(pos==-1) return x^val;
        int c=(x>>pos)&1;c^=1;
        if(cnt[trie[p][c]]==cnt[trie[q][c]])
            return query(trie[p][c^1],trie[q][c^1],x,pos-1,val|((c^1)<<pos));
        else
            return query(trie[p][c],trie[q][c],x,pos-1,val|(c<<pos));
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
        if(son[u])  dfs2(son[u],u);
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p||v==son[u]) continue;
            dfs2(v,u);
        }
        ed[u]=dfsid;
    }
    int querypath(int u,int v,int k){
        int ans=0;
        while(top[u]!=top[v]){
            if(depth[top[u]]>depth[top[v]]){
                ans=max(ans,P01Trie::query(P01Trie::root[dfn[top[u]]-1],P01Trie::root[dfn[u]],k,L,0));
                u=fa[top[u]];
            }else{
                ans=max(ans,P01Trie::query(P01Trie::root[dfn[top[v]]-1],P01Trie::root[dfn[v]],k,L,0));
                v=fa[top[v]];
            }
        }
        if(depth[u]>depth[v])   swap(u,v);
        ans=max(ans,P01Trie::query(P01Trie::root[dfn[u]-1],P01Trie::root[dfn[v]],k,L,0));
        return ans;
    }
    inline int querytree(int u,int k){
        return P01Trie::query(P01Trie::root[dfn[u]-1],P01Trie::root[ed[u]],k,L,0);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    HLD::dfs1(1,0);
    HLD::dfs2(1,0);
    for(int i=1;i<=n;i++)
        P01Trie::insert(P01Trie::root[i],P01Trie::root[i-1],v[rk[i]],L);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==2){
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
            printf("%d\n",HLD::querypath(u,v,k));
        }else{
            int u,k;
            scanf("%d%d",&u,&k);
            printf("%d\n",HLD::querytree(u,k));;
        }
    }
    return 0;
}