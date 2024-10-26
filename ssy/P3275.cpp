#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+10,M=1e5+10;
int n,m;
int head[N],nxt[M],e[M],ver[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dfn[N],low[N],dfsid=0;
int c[N],cnt[N],sccid=0;
stack<int>stk;
bool instk[N];
void tarjan(int u){
    dfn[u]=low[u]=++dfsid;
    stk.push(u);instk[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(instk[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        sccid++;
        int t;
        do{
            t=stk.top();stk.pop();
            instk[t]=0;
            c[t]=sccid;
            cnt[sccid]++;
        }while(t!=u);
    }
}
int hc[N],nc[M],ec[M],vc[M],tc=1;
void addc(int u,int v,int w){
    vc[++tc]=v;ec[tc]=w;nc[tc]=hc[u];hc[u]=tc;
}
int ind[N];
long long dp[N];
queue<int>q;
void toposort(){
    for(int i=1;i<=sccid;i++)
        if(!ind[i]){
            q.push(i);
            dp[i]=1;
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=hc[u];i;i=nc[i]){
            int v=vc[i],w=ec[i];
            ind[v]--;
            dp[v]=max(dp[v],dp[u]+w);
            if(!ind[v]) q.push(v);
        }
    }
}
long long ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,u,v;scanf("%d%d%d",&x,&u,&v);
        switch(x){
            case 1:add(u,v,0);add(v,u,0);break;
            case 2:add(u,v,1);break;
            case 3:add(v,u,0);break;
            case 4:add(v,u,1);break;
            case 5:add(u,v,0);break;
        }
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(c[u]==c[v]&&w==1){printf("-1");return 0;}
            if(c[u]!=c[v]){
                addc(c[u],c[v],w);
                ind[c[v]]++;
            }
        }
    toposort();
    for(int i=1;i<=sccid;i++)
        ans+=dp[i]*cnt[i];
    printf("%lld",ans);
    return 0;
}