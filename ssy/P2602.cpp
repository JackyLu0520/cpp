#include<bits/stdc++.h>
using namespace std;
const int LG=13;
long long a,b,pow10[LG+2]={1},dp[LG+2],cnta[10],cntb[10];
int main(){
    scanf("%lld%lld",&a,&b);
    for(int i=1;i<LG;i++)
        pow10[i]=pow10[i-1]*10;
    for(int i=1;i<LG;i++)
        dp[i]=10*dp[i-1]+pow10[i-1];
    a--;
    for(int i=log10(a);i>=1;i--){
        for(int j=0;j<10;j++)   cnta[j]+=dp[i-1]*(a/pow10[i]%10);
        for(int j=0;j<a/pow10[i]%10;j++)    cnta[j]+=pow10[i-1];
        cnta[a/pow10[i]%10]+=a%pow10[i]+1;
        cnta[0]-=pow10[i-1];
    }
    for(int i=log10(b);i>=1;i--){
        for(int j=0;j<10;j++)   cntb[j]+=dp[i-1]*(b/pow10[i]%10);
        for(int j=0;j<b/pow10[i]%10;j++)    cntb[j]+=pow10[i-1];
        cntb[b/pow10[i]%10]+=b%pow10[i]+1;
        cntb[0]-=pow10[i-1];
    }
    for(int i=0;i<10;i++)   printf("%lld ",cntb[i]-cnta[i]);
    printf("\n");
    for(int i=0;i<10;i++)   printf("%lld ",cntb[i]);
    printf("\n");
    for(int i=0;i<10;i++)   printf("%lld ",cnta[i]);
    printf("\n");
    return 0;
}