#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=5010;
int n,m;
int head[N],nxt[2*M],ver[2*M],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
stack<int>stk;
bool vis[N],cycle[2*M];
void dfs1(int u,int in_edge){
    if(vis[u]){
        int t;
        while(1){
            t=stk.top();stk.pop();
            if(ver[t^1]==u) break;
            cycle[t]=cycle[t^1]=1;
        }
        return;
    }
    stk.push(in_edge);vis[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v!=ver[in_edge^1])   continue;
        dfs1(v,i);
    }
    stk.pop();
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    if(m==n-1){

    }else{

    }
    return 0;
}