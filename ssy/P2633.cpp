#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=22;
int n,m;
int w[N];
vector<int>tmp;
int head[N],nxt[2*N],ver[2*N],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N],fa[N],depth[N];
int top[N],dfn[N],dfsid=0,rk[N];
namespace PSGT{
    struct node{
        int sum;
        int ls,rs;
    }t[N+N*L];int tot=0;
    int root[N];
    inline void pushup(int p){
        t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
    }
    void build(int &p,int l,int r){
        if(!p)  p=++tot;
        if(l==r){t[p].sum=0;return;}
        int mid=(l+r)/2;
        build(t[p].ls,l,mid);
        build(t[p].rs,mid+1,r);
        pushup(p);
    }
    void add(int &p,int q,int i,int k,int pl,int pr){
        if(!p)  p=++tot;
        if(pl==pr){
            t[p].sum=t[q].sum+k;
            return;
        }
        int mid=(pl+pr)/2;
        if(i<=mid)  t[p].rs=t[q].rs,add(t[p].ls,t[q].ls,i,k,pl,mid);
        else        t[p].ls=t[q].ls,add(t[p].rs,t[q].rs,i,k,mid+1,pr);
        pushup(p);
    }
    int query(vector<int>p,vector<int>q,int k,int pl,int pr){
        if(pl==pr)  return pl;
        int sum=0;
        for(int &i:q)   sum+=t[t[i].ls].sum;
        for(int &i:p)   sum-=t[t[i].ls].sum;
        int mid=(pl+pr)/2;
        if(k<=sum){
            for(int &i:q)   i=t[i].ls;
            for(int &i:p)   i=t[i].ls;
            return query(p,q,k,pl,mid);
        }else{
            for(int &i:q)   i=t[i].rs;
            for(int &i:p)   i=t[i].rs;
            return query(p,q,k-sum,mid+1,pr);
        }
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
    }
    int query(int u,int v,int k){
        vector<int>p,q;
        while(top[u]!=top[v]){
            if(depth[top[u]]>depth[top[v]]){
                q.emplace_back(PSGT::root[dfn[u]]);
                p.emplace_back(PSGT::root[dfn[top[u]]-1]);
                u=fa[top[u]];
            }else{
                q.emplace_back(PSGT::root[dfn[v]]);
                p.emplace_back(PSGT::root[dfn[top[v]]-1]);
                v=fa[top[v]];
            }
        }
        if(depth[u]>depth[v])   swap(u,v);
        q.emplace_back(PSGT::root[dfn[v]]);
        p.emplace_back(PSGT::root[dfn[u]-1]);
        return PSGT::query(p,q,k,1,tmp.size());
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        tmp.emplace_back(w[i]);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    HLD::dfs1(1,0);
    HLD::dfs2(1,0);
    PSGT::build(PSGT::root[0],1,tmp.size());
    for(int i=1;i<=n;i++){
        int p=lower_bound(tmp.begin(),tmp.end(),w[rk[i]])-tmp.begin()+1;
        PSGT::add(PSGT::root[i],PSGT::root[i-1],p,1,1,tmp.size());
    }
    int pre=0;
    for(int i=1;i<=m;i++){
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        pre=tmp[HLD::query(u^pre,v,k)-1];
        printf("%d\n",pre);
    }
    return 0;
}