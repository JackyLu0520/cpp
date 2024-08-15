#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int depth[N]={-1},fa[N];
void dfs1(int u,int p){
    fa[u]=p;depth[u]=depth[p]+1;
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p)
            dfs1(ver[i],u);
}
int U=0,V=0,c;
int maxd[N],dis[N];
void dfs2(int u,int p){
    fa[u]=p;depth[u]=depth[p]+1;maxd[u]=depth[u];
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p){
            dfs2(ver[i],u);
            maxd[u]=max(maxd[u],maxd[ver[i]]);
        }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++)
        if(depth[U]<depth[i])
            U=i;
    dfs1(U,0);
    for(int i=1;i<=n;i++)
        if(depth[V]<depth[i])
            V=i;
    c=V;
    for(int i=1;i<=depth[V]/2;i++)
        c=fa[c];
    dfs2(c,0);
    for(int i=1;i<=n;i++)
        dis[i]=maxd[i]-depth[i];
    sort(dis+1,dis+n+1,greater<int>());
    printf("%d",dis[k+1]+1);
    return 0;
}