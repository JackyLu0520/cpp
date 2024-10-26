#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10,M=2e6+10;
int n,m;
int head[N],nxt[2*M],ver[2*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dfn[N],low[N],dfsid=0;
vector<int>dcc[N];
stack<int>stk;
int dccid=0;
void tarjan(int u,int root){
    dfn[u]=low[u]=++dfsid;
    stk.push(u);
    if(u==root&&head[u]==0){
        dcc[++dccid].push_back(u);
        return;
    }
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!dfn[v]){
            tarjan(v,root);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                dccid++;
                int t;
                do{
                    t=stk.top();stk.pop();
                    dcc[dccid].push_back(t);
                }while(t!=v);
                dcc[dccid].push_back(u);
            }
        }else   low[u]=min(low[u],dfn[v]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        if(u==v)    continue;
        add(u,v);add(v,u);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i,i);
    printf("%d\n",dccid);
    for(int i=1;i<=dccid;i++){
        printf("%lld ",dcc[i].size());
        for(auto it=dcc[i].begin();it!=dcc[i].end();it++)
            printf("%d ",*it);
        printf("\n");
    }
    return 0;
}