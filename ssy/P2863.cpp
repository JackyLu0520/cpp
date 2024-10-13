#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e4+10,M=5e4+10;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
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
            t=stk.top();
            stk.pop();
            instk[t]=0;
            c[t]=sccid;
            cnt[sccid]++;
        }while(t!=u);
    }
}
int ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=sccid;i++)
        if(cnt[i]>1)
            ans++;
    printf("%d",ans);
    return 0;
}