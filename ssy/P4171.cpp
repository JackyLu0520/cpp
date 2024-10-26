#include<bits/stdc++.h>
using namespace std;
constexpr int N=110,M=1010;
int n,m;
int head[2*N],nxt[2*M],ver[2*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dfn[2*N],low[2*N],dfsid;
int c[2*N],sccid;
stack<int>stk;
bool instk[2*N];
void clear(){
    memset(head,0,sizeof(head));
    tot=1;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    dfsid=0;
    memset(c,0,sizeof(c));
    sccid=0;
    stack<int>t;swap(t,stk);
    memset(instk,0,sizeof(instk));
}
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
        }while(t!=u);
    }
}
int main(){
    int _;scanf("%d",&_);
    while(_--){
        scanf("%d%d",&n,&m);
        clear();
        for(int i=1;i<=m;i++){
            char a[10],b[10];
            scanf("%s%s",a,b);
            int x,p=(a[0]=='h'),y,q=(b[0]=='h');
            sscanf(a+1,"%d",&x);
            sscanf(b+1,"%d",&y);
            add(x+n*p,y+n*(!q));
            add(y+n*q,x+n*(!p));
        }
        for(int i=1;i<=2*n;i++)
            if(!dfn[i])
                tarjan(i);
        bool f=1;
        for(int i=1;i<=n;i++)
            if(c[i]==c[i+n]){
                f=0;break;
            }
        printf(f?"GOOD\n":"BAD\n");
    }
    return 0;
}