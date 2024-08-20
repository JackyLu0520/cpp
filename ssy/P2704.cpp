#include<bits/stdc++.h>
using namespace std;
const int N=110,M=11;
int n,m,s[N];
bool cur=0;
long long dp[2][1<<M][1<<M],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n+1;i++){
        getchar();
        char t[M+5];scanf("%s",t);
        for(int j=0;j<m;j++)
            s[i]=(s[i]<<1)|(t[j]=='H');
    }
    s[0]=s[1]=(1<<m)-1;
    for(int i=2;i<=n+1;i++){
        cur=!cur;
        memset(dp[cur],0,sizeof(dp[cur]));
        for(int j=0;j<(1<<m);j++)
            if(!(j&(j<<1))&&!(j&(j<<2))&&!(j&s[i]))
                for(int k=0;k<(1<<m);k++)
                    if(!(k&(k<<1))&&!(k&(k<<2))&&!(k&s[i-1])&&!(j&k))
                        for(int l=0;l<(1<<m);l++)
                            if(!(l&(l<<1))&&!(l&(l<<2))&&!(l&s[i-2])&&!(k&l)&&!(j&l))
                                dp[cur][j][k]=max(dp[cur][j][k],dp[!cur][k][l]+__builtin_popcount(j));
    }
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++)
            ans=max(ans,dp[cur][i][j]);
    printf("%lld",ans);
    return 0;
}