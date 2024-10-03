#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e3+10;
int n,dis[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&dis[i][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=max(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",dis[i][j]);
        printf("\n");
    }
    return 0;
}