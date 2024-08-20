#include<bits/stdc++.h>
using namespace std;
const int N=110,M=11;
int n,m,s[N],dp[N][1<<M][1<<M],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=0;j<m;j++)
            s[i]=(s[i]<<1)|(getchar()=='H');
    }
    s[0]=s[1]=(1<<m)-1;
    for(int i=2;i<=n+1;i++)
        for(int j=0;j<(1<<m);j++)
            if(!(j&(j<<1))&&!(j&(j<<2))&&!(j&s[i]))
                for(int k=0;k<(1<<m);k++)
                    if(!(k&(k<<1))&&!(k&(k<<2))&&!(k&s[i-1])&&!(j&k))
                        for(int l=0;l<(1<<m);l++)
                            if(!(l&(l<<1))&&!(l&(l<<2))&&!(l&s[i-2])&&!(k&l)&&!(j&l))
                                dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+__builtin_popcount(j));
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++)
            ans=max(ans,dp[n+1][i][j]);
    printf("%d",ans);
    return 0;
}