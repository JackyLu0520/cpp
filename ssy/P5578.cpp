#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=2e5+10,L=20,K=5e5+10;
int n,m,k;
int g[N];
int fa[N+M][L],depth[N+M];
int p[N];
int lca(int u,int v){
    if(depth[u]<depth[v])   swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1) u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];v=fa[v][i];
        }
    return fa[u][0];
}
struct R{
    int x,y,pri,id;
    bool operator < (const R& a) const{
        return pri==a.pri?id<a.id:pri>a.pri;
    }
}r[K];int tot=0;
int ans=0;
signed main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&g[i]);
    for(int i=1;i<=n;i++)
        p[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        fa[p[x]][0]=n+i;
        fa[p[y]][0]=n+i;
        p[y]=n+i;
    }
    for(int j=1;j<L;j++)
        for(int i=n+m;i>=1;i--)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    for(int i=n+m;i>=1;i--)
        depth[i]=depth[fa[i][0]]+1;
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        int t=lca(x,y);
        if(!t)  continue;
        tot++;
        r[tot].x=x;r[tot].y=y;
        r[tot].pri=depth[t];
        r[tot].id=tot;
    }
    sort(r+1,r+tot+1);
    for(int i=1;i<=tot;i++){
        int x=r[i].x,y=r[i].y;
        int t=min(g[x],g[y]);
        g[x]-=t,g[y]-=t;
        ans+=2*t;
    }
    /*for(int i=1;i<=n+m;i++)
        if(fa[i][0])
            printf("%lld %lld\n",i,fa[i][0]);
    printf("\n");*/
    printf("%lld",ans);
    return 0;
}