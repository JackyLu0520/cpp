#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,L=20;
int n,k,q;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
//lca
int fa[N][L],depth[N];
void dfs(int u,int p){
    fa[u][0]=p;depth[u]=depth[p]+1;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v!=p)    dfs(v,u);
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
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];v=fa[v][i];
        }
    return fa[u][0];
}
//bfs
queue<int>Q;
int d[N];
void bfs(){
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(d[v]==0x3f3f3f3f){
                d[v]=d[u]+1;
                Q.push(v);
            }
        }
    }
}
//main
int main(){
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=k;i++){
        int t;
        scanf("%d",&t);
        d[t]=0;
        Q.push(t);
    }
    bfs();
    for(int i=1;i<=q;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",min(depth[u]+depth[v]-2*depth[lca(u,v)],d[u]+d[v]));
    }
    return 0;
}