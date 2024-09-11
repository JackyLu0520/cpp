#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5+10;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ans[N]={0},vis[N]={0};
void dfs(int u,int c){
    if(vis[u])  return;
    ans[u]=c;vis[u]=1;
    for(int i=head[u];i;i=nxt[i])
        dfs(ver[i],c);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(v,u);
    }
    for(int i=n;i>=1;i--)
        dfs(i,i);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}