#include<bits/stdc++.h>
using namespace std;
long long binpow(long long a,long long b,long long p){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}
int main(){
    long long a,b,p;
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,binpow(a,b,p));
    return 0;
}