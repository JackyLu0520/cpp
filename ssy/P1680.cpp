#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll n,m;
ll binpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll C(ll a,ll b){
    if(b>a) return 0;
    ll up=1,down=1;
    for(ll i=1,j=a;i<=b;i++,j--)
        up=(up*j)%MOD,down=(down*i)%MOD;
    return (up*binpow(down,MOD-2))%MOD;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++){
        ll c;scanf("%lld",&c);
        n-=c;
    }
    printf("%lld",C(n-1,m-1));
    return 0;
}