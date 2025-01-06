#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=22;
int n,m;
int head[N],nxt[2*N],ver[2*N],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int fa[N][L],depth[N];
void dfs1(int u,int p){
    fa[u][0]=p;depth[u]=depth[p]+1;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs1(v,u);
    }
}
int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1) u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
map<int,int>cnt[N];
int mx[N],ans[N];
inline void mapadd(map<int,int>&mp,int i,int k){
    if(!mp.count(i))    mp[i]=0;
    mp[i]+=k;
}
void dfs2(int u,int p){
    for(auto &i:cnt[u])
        if(i.second>mx[u])
            mx[u]=i.second,ans[u]=i.first;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs2(v,u);
        if(cnt[u].size()<cnt[v].size()){
            cnt[u].swap(cnt[v]);
            mx[u]=mx[v];
            ans[u]=ans[v];
        }
        for(auto &i:cnt[v]){
            mapadd(cnt[u],i.first,i.second);
            if(cnt[u][i.first]>mx[u])
                mx[u]=cnt[u][i.first],ans[u]=i.first;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs1(1,0);
    for(int i=1;i<=m;i++){
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        int l=lca(u,v);
        mapadd(cnt[u],k,1);
        mapadd(cnt[v],k,1);
        mapadd(cnt[l],k,-1);
        if(fa[l][0])
            mapadd(cnt[fa[l][0]],k,-1);
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}