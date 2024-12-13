#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=2e5+10,L=20;
int n,m;
struct E{
    int u,v,w;
    bool operator<(const E& a)const{
        return w<a.w;
    }
}e[M],e1[M];
struct dsu{
    int fa[N];
    dsu(int n){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    bool merge(int x,int y){
        int xx=query(x),yy=query(y);
        if(xx==yy)  return 0;
        fa[xx]=yy;
        return 1;
    }
};
int head[N],nxt[2*N],ver[2*N],ew[2*N],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;ew[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int ans=0;
void kruskal(){
    sort(e+1,e+m+1);
    dsu d(n);
    for(int i=1;i<=m;i++)
        if(d.merge(e[i].u,e[i].v)){
            ans+=e[i].w;
            add(e[i].u,e[i].v,e[i].w);
            add(e[i].v,e[i].u,e[i].w);
        }
}
int fa[N][L],maxw[N][L],depth[N];
void dfs(int u,int in_edge){
    depth[u]=depth[ver[in_edge^1]]+1;
    fa[u][0]=ver[in_edge^1];
    maxw[u][0]=ew[in_edge];
    for(int i=1;i<L;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
        maxw[u][i]=max(maxw[u][i-1],maxw[fa[u][i-1]][i-1]);
    }
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==ver[in_edge^1])    continue;
        dfs(v,i);
    }
}
int solve(int u,int v){
    int ans=0;
    if(depth[u]<depth[v])
        swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1){
            ans=max(ans,maxw[u][i]);
            u=fa[u][i];
        }
        t>>=1;
    }
    if(u==v)    return ans;
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            ans=max(ans,max(maxw[u][i],maxw[v][i]));
            u=fa[u][i];
            v=fa[v][i];
        }
    return max(ans,max(maxw[u][0],maxw[v][0]));
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
        e1[i]=e[i];
    }
    kruskal();
    dfs(1,0);
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans-solve(e1[i].u,e1[i].v)+e1[i].w);
    return 0;
}