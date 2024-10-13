#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e4+10,M=1e5+10;
int n,m,w[N];
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}

stack<int>stk;
bool instk[N];
int dfn[N],low[N],dfsid=0;
int c[N],sccid=0,wc[N];
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
            t=stk.top();
            stk.pop();
            instk[t]=0;
            c[t]=sccid;
            wc[sccid]+=w[t];
        }while(t!=u);
    }
}
int hc[N],nc[M],vc[M],tc=1;
void addc(int u,int v){
    vc[++tc]=v;nc[tc]=hc[u];hc[u]=tc;
}
queue<int>q;
int ind[N],dp[N];
void toposort(){
    for(int i=1;i<=sccid;i++)
        if(!ind[i]){
            q.push(i);
            dp[i]=wc[i];
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=hc[u];i;i=nc[i]){
            int v=vc[i];
            ind[v]--;
            dp[v]=max(dp[v],dp[u]+wc[v]);
            if(!ind[v]) q.push(v);
        }
    }
}
int ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(c[u]!=c[v]){
                addc(c[u],c[v]);
                ind[c[v]]++;
            }
        }
    toposort();
    for(int i=1;i<=sccid;i++)
        ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}