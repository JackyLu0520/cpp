#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1010;
int n,m,ans=0;
int a[N][M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=2;i<=n;i+=3)
        for(int j=2;j<=m;j+=3)
            ans+=a[i][j];
    printf("%d",ans);
    return 0;
}