#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,L=17;
int n,k;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int depth[N],fa[N][L];
void dfs1(int u,int p){
    depth[u]=depth[p]+1;fa[u][0]=p;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p)
            dfs1(ver[i],u);
}
int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1) u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];v=fa[v][i];
        }
    return fa[u][0];
}
int s[N];
void dfs2(int u,int p){
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p){
            dfs2(ver[i],u);
            s[u]+=s[ver[i]];
        }
}
int ans=0;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs1(1,0);
    while(k--){
        int u,v;
        scanf("%d%d",&u,&v);
        int t=lca(u,v);
        s[u]++;s[v]++;s[t]--;s[fa[t][0]]--;
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        ans=max(ans,s[i]);
    printf("%d",ans);
    return 0;
}