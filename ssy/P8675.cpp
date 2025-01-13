#include<bits/stdc++.h>
using namespace std;
const int N=110,M=110;
int n,m;
int dp[N][M][M],s[M][M];
int a[N][M],ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++){
            int c;
            scanf(" %c",&c);
            a[i][j]=a[i][j-1]+(c=='X');
        }
    for(int l=1;l<=m;l++)
        for(int r=l;r<=m;r++){
            dp[1][l][r]=(a[1][l-1]==a[1][r]);
        }
    for(int l=1;l<=m;l++)
        for(int r=1;r<=m;r++)
            s[l][r]=dp[1][l][r]+s[l][r-1]+s[l-1][r]-s[l-1][r-1];
    for(int i=2;i<=n;i++){
        for(int l=1;l<=m;l++)
            for(int r=l;r<=m;r++)
                if(a[1][l-1]==a[1][r])
                    dp[i][l][r]=s[l][m]-s[l][r-1];
        for(int l=1;l<=m;l++)
            for(int r=1;r<=m;r++)
                s[l][r]=dp[i][l][r]+s[l][r-1]+s[l-1][r]-s[l-1][r-1];
    }
    for(int l=1;l<=m;l++)
        for(int r=l;r<=m;r++)
            ans+=dp[n][l][r];
    printf("%d",ans);
    return 0;
}