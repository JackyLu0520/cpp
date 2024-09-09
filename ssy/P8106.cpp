#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
ll binpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
ll C(ll n,ll m){
    ll up=1,down=1;
    for(int i=1,j=n;i<=m;i++,j--)
        up=(up*j)%MOD,down=(down*i)%MOD;
    return up*binpow(down,MOD-2)%MOD;
}
int main(){
    ll n;scanf("%lld",&n);
    if(n==1){printf("0");return 0;}
    ll ans=binpow(2,n-2);
    if(n%2==0)  ans-=C(n-2,(n-2)/2);
    printf("%lld",(ans%MOD+MOD)%MOD);
    return 0;
}