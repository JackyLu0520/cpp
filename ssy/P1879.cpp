#include<bits/stdc++.h>
using namespace std;
const int N=13,M=13,MOD=1e8;
int n,m,s[N],dp[N][1<<M],ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++){
            int x;scanf("%d",&x);
            s[i]=(s[i]<<1)|(!x);
        }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<m);j++)
            if(!(j&(j<<1))&&!(j&s[i]))
                for(int k=0;k<(1<<m);k++)
                    if(!(j&k))
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
    for(int i=0;i<(1<<m);i++)   ans=(ans+dp[n][i])%MOD;
    printf("%d",ans);
    return 0;
}