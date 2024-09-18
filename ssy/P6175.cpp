#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,g[N][N],dis[N][N],ans=0x2a2a2a2a;
int main(){
    scanf("%d%d",&n,&m);
    memset(g,0x2a,sizeof(g));
    memset(dis,0x2a,sizeof(dis));
    for(int i=1;i<=n;i++)
        g[i][i]=dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        if(u==v)    continue;
        g[u][v]=dis[u][v]=g[v][u]=dis[v][u]=min(g[u][v],w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(i!=j&&i!=k&&k!=j)
                    ans=min(ans,dis[i][j]+g[i][k]+g[k][j]);
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
    if(ans==0x2a2a2a2a) printf("No solution.");
    else                printf("%d",ans);
    return 0;
}