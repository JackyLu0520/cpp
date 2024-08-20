#include<bits/stdc++.h>
using namespace std;
const int N=10,M=1<<N,K=N*N;
int n,cnt;
long long dp[N][M][K],ans=0;
int main(){
    scanf("%d%d",&n,&cnt);
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<n);j++)
            if(!(j&(j<<1)))
                for(int k=0;k<(1<<n);k++)
                    if(!(j&k)&&!(j&(k<<1))&&!((j<<1)&k))
                        for(int l=cnt;l>=__builtin_popcount(j);l--)
                            dp[i][j][l]+=dp[i-1][k][l-__builtin_popcount(j)];
    for(int i=0;i<(1<<n);i++)
        ans+=dp[n][i][cnt];
    printf("%lld",ans);
    return 0;
}