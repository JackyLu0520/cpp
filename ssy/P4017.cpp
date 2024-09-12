#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=5e5+10,MOD=80112002;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ind[N]={0},outd[N]={0};
queue<int>q;
int dp[N],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);ind[v]++;outd[u]++;
    }
    for(int i=1;i<=n;i++)
        if(!ind[i]){
            q.push(i);
            dp[i]=1;
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            dp[v]=(dp[v]+dp[u])%MOD;
            ind[v]--;
            if(!ind[v])q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        if(!outd[i])
            ans=(ans+dp[i])%MOD;
    printf("%d",ans);
    return 0;
}