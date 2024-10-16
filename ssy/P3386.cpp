#include<bits/stdc++.h>
using namespace std;
constexpr int N=510,M=510,E=5e4+10;
int n,m,e;
int head[N+M],nxt[E],ver[E],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int vis[M],match[M];
bool dfs(int u){
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!vis[v]){
            vis[v]=1;
            if(!match[v]||dfs(match[v])){
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int ans=0;
int main(){
    scanf("%d%d%d",&n,&m,&e);
    for(int i=1;i<=e;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        ans+=dfs(i);
    }
    printf("%d",ans);
    return 0;
}