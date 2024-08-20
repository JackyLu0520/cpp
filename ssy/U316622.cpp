#include<bits/stdc++.h>
using namespace std;
const int N=25,M=110,MOD=1e9+7;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int cnt[M],vis[N];
int dfs(int u,int in_edge){
    vis[u]=1;
    int ret=1;
    for(int i=head[u];i;i=nxt[i])
        if(!vis[ver[i]])
            ret=(ret+dfs(ver[i],i))%MOD;
    vis[u]=0;cnt[in_edge]=(cnt[in_edge]+ret)%MOD;
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++)
        dfs(i,0);
    for(int i=2;i<=tot;i++)
        printf("%d\n",cnt[i]);
    return 0;
}