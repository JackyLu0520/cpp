#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,v[N];
vector<pair<int,int>>s[N];
int dp[N][N],cnt[N];
void dfs(int u){
    cnt[u]=1;
    if(u>n-m){
        dp[u][1]=v[u];
        return;
    }
    for(pair<int,int> i:s[u]){
        int v=i.first,w=i.second;
        dfs(v);cnt[u]+=cnt[v];
        for(int j=cnt[u];j>0;j--)
            for(int k=1;k<=cnt[v];k++)
                if(j-k>=0)
                    dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]-w);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int u=1;u<=n-m;u++){
        int k;scanf("%d",&k);
        while(k--){
            int v,w;scanf("%d%d",&v,&w);
            s[u].push_back(make_pair(v,w));
        }
    }
    for(int i=n-m+1;i<=n;i++)
        scanf("%d",&v[i]);
    memset(dp,~0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    dfs(1);
    for(int i=m;i>=1;i--)
        if(dp[1][i]>=0){
            printf("%d",i);
            break;
        }
    return 0;
}