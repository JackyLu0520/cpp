#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int depth[N];
void dfs(int u,int p){
    depth[u]=depth[p]+1;
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p)
            dfs(ver[i],u);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    int m=0;
    for(int i=1;i<=n;i++)
        if(depth[m]<depth[i])
            m=i;
    dfs(m,0);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,depth[i]);
    printf("%d",ans-1);
    return 0;
}