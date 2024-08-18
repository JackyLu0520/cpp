#include<bits/stdc++.h>
using namespace std;
const long long LG=20,MOD=1e9+7;
long long t,a,b,pow10[LG+2]={1},dp[LG+2],ans=0;
int main(){
    for(int i=1;i<LG;i++)
        pow10[i]=pow10[i-1]*10;
    for(int i=1;i<LG;i++)
        dp[i]=10*dp[i-1]+pow10[i-1];
    scanf("%lld",&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&a,&b);
        for(int i=log10(b)+1;i>=1;i--){
            for(int j=0;j<10;j++)   ans=(ans+(j*dp[i-1])%MOD*(b/pow10[i-1]%10)%MOD)%MOD;
            for(int j=0;j<b/pow10[i-1]%10;j++)    ans=(ans+j*pow10[i-1]%MOD)%MOD;
            ans=(ans+((b/pow10[i-1]%10)%MOD)*(b%pow10[i-1]+1)%MOD)%MOD;
        }
        a--;
        for(int i=log10(a)+1;i>=1;i--){
            for(int j=0;j<10;j++)   ans=(ans-(j*dp[i-1])%MOD*(a/pow10[i-1]%10)%MOD)%MOD;
            for(int j=0;j<a/pow10[i-1]%10;j++)    ans=(ans-j*pow10[i-1]%MOD)%MOD;
            ans=(ans-((a/pow10[i-1]%10)%MOD)*(a%pow10[i-1]+1)%MOD)%MOD;
        }
        printf("%lld\n",(ans+MOD)%MOD);
    }
    return 0;
}