#include<bits/stdc++.h>
using namespace std;
const int MOD=200907;
long long binpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int main(){
    long long t;scanf("%lld",&t);
    while(t--){
        long long a,b,c,k;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        if(c-b==b-a)
            printf("%lld\n",(a%MOD+((b-a)%MOD*(k-1)%MOD)%MOD)%MOD);
        else
            printf("%lld\n",(a*binpow(b/a,k-1))%MOD);
    }
    return 0;
}