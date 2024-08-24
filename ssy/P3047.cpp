#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,K=25;
int n,k;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int c[N],dp1[N][K],dp2[N][K];
void dfs1(int u,int p){
    for(int i=0;i<=k;i++)   dp1[u][i]=c[u];
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p){
            dfs1(ver[i],u);
            for(int j=1;j<=k;j++)
                dp1[u][j]+=dp1[ver[i]][j-1];
        }
}
void dfs2(int u,int p){
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p){
            dp2[ver[i]][1]+=dp1[u][0];
            for(int j=2;j<=k;j++)
                dp2[ver[i]][j]+=dp2[u][j-1]-dp1[ver[i]][j-2];
            dfs2(ver[i],u);
        }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    dfs1(1,0);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp2[i][j]=dp1[i][j];
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",dp2[i][k]);
    return 0;
}