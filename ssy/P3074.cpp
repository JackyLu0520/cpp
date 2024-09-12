#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=5e4+10;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int len[N],ind[N]={0};
queue<int>q;
int dp[N],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&len[i]);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);ind[v]++;
    }
    for(int i=1;i<=n;i++)
        if(!ind[i]){
            q.push(i);
            dp[i]=len[i];
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            dp[v]=max(dp[v],dp[u]+len[v]);
            ind[v]--;
            if(!ind[v])q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}