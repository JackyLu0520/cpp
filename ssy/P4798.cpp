#include<bits/stdc++.h>
using namespace std;
const long long N=10010,MOD=1e6+7;
long long n,a[N],dp[N],mx[N],ans;
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        dp[i]=1;mx[i]=max(mx[i-1],a[i]);
    }
    for(long long i=n;i>=1;i--){
        for(long long j=1;j<=min(mx[i-1]+1,a[i]-1);j++)   ans=(ans+dp[max(j+1,mx[i-1]+1)])%MOD;
        for(long long j=1;j<=i;j++)   dp[j]=((j-1)*dp[j]+dp[j+1])%MOD;
    }
    printf("%lld",(ans+1)%MOD);
    return 0;
}