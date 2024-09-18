#include<bits/stdc++.h>
using namespace std;
const int N=65,L=65;
int n,m;
int a[N][N],dp[N][N][L];
int main(){
    memset(a,0x3f,sizeof a);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        a[u][v]=1;dp[u][v][0]=1;
    }
    for(int t=1;t<L;t++)
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(dp[i][k][t-1]&&dp[k][j][t-1]){
                        dp[i][j][t]=1;
                        a[i][j]=1;
                    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    printf("%d",a[1][n]);
    return 0;
}