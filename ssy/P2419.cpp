#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,g[N][N],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        g[u][v]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]|=g[i][k]&g[k][j];
    for(int i=1;i<=n;i++){
        bool f=1;
        for(int j=1;j<=n;j++){
            if(i==j)    continue;
            f&=g[i][j]|g[j][i];
        }
        ans+=f;
    }
    printf("%d",ans);
    return 0;
}