#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000,MOD=998244353;
int n,q,fa[MAXN+10][20]={0},depth[MAXN+10],w[MAXN+10][20]={0},base=0;
struct E{int v,w;E(int V,int W){v=V;w=W;}};
vector<E> adj[MAXN+10];
void dfs(int u,int pre){
    for(int i=1;i<20;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
        w[u][i]=(w[u][i-1]+w[fa[u][i-1]][i-1])%MOD;
    }
    for(auto e:adj[u])
        if(e.v!=pre){
            fa[e.v][0]=u;
            depth[e.v]=depth[u]+1;
            w[e.v][0]=e.w;
            dfs(e.v,u);
        }
}
int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);
    int diff=depth[u]-depth[v],ans=0;
    for(int i=0;diff;i++){
        if(diff&1)  ans=(ans+w[u][i])%MOD,u=fa[u][i];
        diff>>=1;
    }
    if(u==v)    return ans;
    for(int i=19;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            ans=(ans+w[u][i]+w[v][i])%MOD;
            u=fa[u][i];
            v=fa[v][i];
        }
    ans=(ans+w[u][0]+w[v][0])%MOD;
    return ans;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(E(v,w));
        adj[v].push_back(E(u,w));
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            base=(base+lca(i,j))%MOD;
    //cout<<base<<endl;
    while(q--){
        int k,c,ans=base;
        scanf("%d%d",&k,&c);
        fa[n+1][0]=k;
        depth[n+1]=depth[k]+1;
        w[n+1][0]=c;
        for(int i=1;i<20;i++){
            fa[n+1][i]=fa[fa[n+1][i-1]][i-1];
            w[n+1][i]=(w[n+1][i-1]+w[fa[n+1][i-1]][i-1])%MOD;
        }
        //printf("\n");
        for(int i=1;i<=n;i++){
            ans=(ans+lca(i,n+1)*2)%MOD;
            //printf("%d->%d:%d\n",i,n+1,lca(i,n+1));
        }
        printf("%d\n",ans);
    }
    return 0;
}