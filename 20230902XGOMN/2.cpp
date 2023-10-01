#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
int a[2010][2010];
int dirs[5][2]={{0,1},{1,0},{0,-1},{-1,0},{0,0}};
long long b[11];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            b[a[i][j]]++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ans+=b[a[i][j]];
            for(int l=0;l<5;l++){
                int tx=i+dirs[l][0],ty=j+dirs[l][1];
                if(a[tx][ty]==a[i][j])    ans--;
            }
        }
    printf("%lld",ans);
    return 0;
}