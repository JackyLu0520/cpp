#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=5010;
int n,m;
int head[N],nxt[2*M],ver[2*M],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
vector<int>stk;
bool vis[N],cycle[2*M],flag=0;
void dfs1(int u,int in_edge){
    printf("---%d->%d\n",in_edge,u);
    if(vis[u]){
        if(flag)return;
        cycle[in_edge]=cycle[in_edge^1]=1;
        int t;
        auto it=stk.end();
        do{
            t=*it;it--;
            cycle[t]=cycle[t^1]=1;
        }while(ver[t^1]!=u&&u!=0);
        flag=1;
        return;
    }
    stk.push_back(in_edge);vis[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==ver[in_edge^1])   continue;
        dfs1(v,i);
    }
    stk.pop_back();
}
void dfs2(int u,int p){

}
vector<int>g[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        sort(g[i].begin(),g[i].end());
    if(m==n-1){

    }else{
        dfs1(1,0);
        memset(vis,0,sizeof(vis));
    }
    return 0;
}