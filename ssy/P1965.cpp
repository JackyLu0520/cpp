#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x;
long long binpow(long long a,long long b,const long long mod){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    printf("%lld",(x+binpow(10,k,n)*m%n)%n);
    return 0;
}