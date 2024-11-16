#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int head[N],nxt[2*N],ver[2*N],tot=1;
bool dir[2*N];
void add(int u,int v,bool d){
    ver[++tot]=v;dir[tot]=d;nxt[tot]=head[u];head[u]=tot;
}
int f[N],g[N];
void dfs1(int u,int p){//f
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs1(v,u);
        f[u]+=f[v]+(!dir[i]);
    }
}
void dfs2(int u,int p){
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        g[v]=g[u]+f[u]-f[v];
        if(dir[i])  g[v]++;
        else        g[v]--;
        dfs2(v,u);
    }
}
int ans=0x3f3f3f3f;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v,1);add(v,u,0);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        ans=min(ans,f[i]+g[i]);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(f[i]+g[i]==ans)
            printf("%d ",i);
    printf("\n");
    return 0;
}