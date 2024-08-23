#include<bits/stdc++.h>
using namespace std;
const int N=1510;
int n;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dp[N][2];
void dfs(int u,int p){
    dp[u][1]=1;dp[u][0]=0;
    for(int i=head[u];i!=-1;i=nxt[i])
        if(ver[i]!=p){
            dfs(ver[i],u);
            dp[u][0]+=dp[ver[i]][1];
            dp[u][1]+=min(dp[ver[i]][0],dp[ver[i]][1]);
        }
}
int main(){
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        int u,k;scanf("%d%d",&u,&k);
        for(int j=1;j<=k;j++){
            int v;scanf("%d",&v);
            add(u,v);add(v,u);
        }
    }
    dfs(0,-1);
    printf("%d",min(dp[0][0],dp[0][1]));
    return 0;
}