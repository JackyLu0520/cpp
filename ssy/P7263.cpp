#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,ans=1,t;
ll binpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld",&n);getchar();
    t=0;
    for(int i=1;i<=2*n;i++){
        t+=getchar()=='('?1:-1;
        if(!t)  ans=(ans*2)%MOD;
    }
    for(int i=1;i<=n;i++)
        ans=(ans*i)%MOD;
    t=1;
    for(int i=n+1;i<=2*n;i++)
        t=(t*i)%MOD;
    ans=(ans*binpow(t,MOD-2))%MOD;
    printf("%lld",ans);
    return 0;
}