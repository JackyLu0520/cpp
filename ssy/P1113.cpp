#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=110;
int n;
int head[N],nxt[N*M],ver[N*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int len[N],ind[N]={0};
queue<int>q;
int dp[N],ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int v;
        scanf("%d",&v);
        scanf("%d",&len[v]);
        while(1){
            int u;scanf("%d",&u);
            if(u==0)    break;
            add(u,v);ind[v]++;
        }
        if(!ind[v]){
            q.push(v);
            dp[v]=len[v];
        }
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