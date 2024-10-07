#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e4+10,K=25;
int n,k;
int head[N],nxt[2*N],e[2*N],ver[2*N],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dp[N][N],sz[N];
void dfs(int u,int p){
    sz[u]=1;
    memset(dp[u],0x3f,sizeof(dp[u]));
    dp[u][0]=dp[u][1]=0;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i],w=e[i];
        if(v!=p){
            dfs(v,u);
            sz[u]+=sz[v];
            for(int j=sz[u];j>=1;j--)
                for(int l=max(0,sz[v]-k);l<=min(j,sz[v]);l++)
                    dp[u][j]=min(dp[u][j],dp[u][j-l]+dp[v][l]+w);
        }
    }
}
int ans=0x3f3f3f3f;
int main(){
    freopen("center.in","r",stdin);
    freopen("center.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        if(sz[i]>=n-k)
            ans=min(ans,dp[i][n-k]);
    printf("%d",ans*2);
    return 0;
}