#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int n,m,k;
ll dis[N][N],dis1[N][N];
bool check(int x){
    memset(dis1,0x3f,sizeof(dis1));
    for(int i=1;i<=n;i++)
        dis1[i][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&dis[i][j]<=x)
                dis1[i][j]=1;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dis1[i][j]>k)
                return 0;
    return 1;
}
int main(){
    freopen("portal.in","r",stdin);
    freopen("portal.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        dis[u][v]=w;dis[v][u]=w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    long long l=0,r=0x3f3f3f3f3f3f3f3f;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))  r=mid;
        else            l=mid+1;
    }
    printf("%lld",l);
    return 0;
}