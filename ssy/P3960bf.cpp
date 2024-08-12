#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,M=3e5+10;
int n,m,q,a[N][M];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[N][M]=(i-1)*m+j;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int num=a[x][y];
        printf("%d\n",num);
        for(int j=y;j<m;j++)
            a[x][j]=a[x][j+1];
        for(int i=x;i<n;i++)
            a[i][m]=a[i+1][m];
        a[n][m]=num;
    }
    return 0;
}