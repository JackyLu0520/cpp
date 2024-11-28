#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int fa[N],h[N],dep[N];
int head[N],nxt[N],ver[N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
void dfs1(int u){
    h[u]=0x3f3f3f3f;dep[u]=dep[fa[u]]+1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        dfs1(v);
        h[u]=min(h[u],h[v]+1);
    }
    if(h[u]==0x3f3f3f3f)    h[u]=1;
}
int lca[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&fa[i]);
        add(fa[i],i);
    }
    dfs1(1);
    for(int i=1;i<=n+1;i++)
        lca[i]=n+1;
    dep[n+1]=n+1;
    for(int i=1;i<=n;i++)
        if(dep[i]<dep[lca[h[i]+dep[i]-1]])
            lca[h[i]+dep[i]-1]=i;
    for(int i=n;i>=1;i--)
        if(lca[i]==n+1)
            lca[i]=lca[i+1];
    #ifdef DEBUG
    for(int i=1;i<=n;i++)
        printf("%d ",dep[i]+h[i]-1);
    printf("\n");
    for(int i=1;i<=n;i++)
        printf("%d ",lca[i]);
    printf("\n");
    #endif
    while(m--){
        int k;scanf("%d",&k);
        printf("%d\n",lca[k]);
    }
    return 0;
}