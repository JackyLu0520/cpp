#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+10,M=1e6+10;
int n,m;
int head[2*N],nxt[2*M],ver[2*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dfn[2*N],low[2*N],dfsid=0;
int c[2*N],sccid=1;
stack<int>stk;
bool instk[2*N];
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
            c[t]=sccid;
            instk[t]=0;
        }while(t!=u);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,a,y,b;
        scanf("%d%d%d%d",&x,&a,&y,&b);
        add(x+n*a,y+n*(!b));
        add(y+n*b,x+n*(!a));
    }
    for(int i=1;i<=2*n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=n;i++)
        if(c[i]==c[i+n]){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    printf("POSSIBLE\n");
    for(int i=1;i<=n;i++)
        printf("%d ",int(c[i]<c[i+n]));
    return 0;
}