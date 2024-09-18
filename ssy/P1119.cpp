#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n,m,q,t[N],dis[N][N],k=1;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        u++,v++;dis[u][v]=w;dis[v][u]=w;
    }
    scanf("%d",&q);
    while(q--){
        int u,v,x;scanf("%d%d%d",&u,&v,&x);
        u++,v++;
        while(t[k]<=x&&k<=n){
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            k++;
        }
        if(t[u]>x||t[v]>x||dis[u][v]==0x3f3f3f3f)   printf("-1\n");
        else    printf("%d\n",dis[u][v]);
    }
    return 0;
}