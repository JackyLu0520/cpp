#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,q;
int head[N],nxt[2*N],ver[2*N],e[2*N],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dp[N][N],cnt[N];
void dfs(int u,int p){
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p){
            dfs(ver[i],u);
            cnt[u]+=cnt[ver[i]]+1;
            for(int j=min(cnt[u],q);j>0;j--)
                for(int k=min(cnt[ver[i]],j-1);k>=0;k--)
                    dp[u][j]=max(dp[u][j],dp[u][j-k-1]+dp[ver[i]][k]+e[i]);
        }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dfs(1,0);
    printf("%d",dp[1][q]);
    return 0;
}