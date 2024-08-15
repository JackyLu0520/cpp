#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,L=20;
int n,m;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int depth[N],fa[N][L];
void dfs(int u,int p){
    depth[u]=depth[p]+1;fa[u][0]=p;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p)
            dfs(ver[i],u);
}
int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1) u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i>0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int t1=lca(x,y),t2=lca(y,z),t3=lca(x,z);
        int t;
        if(t1==t2) t=t3;
        else if(t2==t3) t=t1;
        else if(t1==t3) t=t2;
        printf("%d %d\n",t,depth[x]+depth[y]+depth[z]-depth[t1]-depth[t2]-depth[t3]);
    }
    return 0;
}