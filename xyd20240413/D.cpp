#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}

int dfn[N],low[N],dfsid;
int stk[N],top=0,ins[N];
int c[N],sccid;
void tarjan(int u){
    dfn[u]=low[u]=++dfsid;
    stk[++top]=u;ins[u]=1;
    for(int i=head[u];i;i=nxt[i])
        if(!dfn[ver[i]]){
            tarjan(ver[i]);
            low[u]=min(low[u],low[ver[i]]);
        }else if(ins[ver[i]])
            low[u]=min(low[u],dfn[ver[i]]);
    if(dfn[u]==low[u]){
        sccid++;
        int t;
        do{
            t=stk[top--];ins[t]=0;
            c[t]=sccid;
        }while(t!=u);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    printf("%d\n",sccid);
    for(int i=1;i<=n;i++)
        printf("%d ",c[i]);
    return 0;
}