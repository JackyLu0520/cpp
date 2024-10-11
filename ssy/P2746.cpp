#include<bits/stdc++.h>
using namespace std;
constexpr int N=105,M=10010;
int n;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}

stack<int>stk;
bool instk[N];
int dfn[N],low[N],dfsid=0;
int c[N],sccid=0;
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
        }while(t!=u);
    }
}
int ind[N],outd[N];
int cnt1=0,cnt2=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t;
        while(1){
            scanf("%d",&t);
            if(t==0)    break;
            add(i,t);
        }
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(c[u]!=c[v])
                ind[c[v]]++,outd[c[u]]++;
        }
    for(int i=1;i<=sccid;i++){
        if(ind[i]==0)   cnt1++;
        if(outd[i]==0)  cnt2++;
    }
    printf("%d\n%d",cnt1,sccid==1?0:max(cnt1,cnt2));
    return 0;
}