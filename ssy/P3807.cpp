#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binpow(ll a,ll b,ll p){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}
ll C(ll n,ll m,ll p){
    if(n<m) return 0;
    ll up=1,down=1;
    for(ll i=n,j=1;j<=m;i--,j++)
        up=(up*i)%p,down=(down*j)%p;
    return up*binpow(down,p-2,p)%p;
}
ll lucas(ll n,ll m,ll p){
    if(n<p&&m<p)    return C(n,m,p);
    return (C(n%p,m%p,p)*lucas(n/p,m/p,p))%p;
}
int main(){
    ll t,n,m,p;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&p);
        printf("%lld\n",lucas(n+m,n,p));
    }
    return 0;
}