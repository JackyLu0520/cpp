#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll q,n,t,ans;
ll binpow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1) ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    scanf("%lld",&q);
    while(q--){
        ll x,y;
        scanf("%lld%lld%lld",&x,&y,&n);
        t=y/x;ans=1;
        for(ll i=2;i*i<=t;i++)
            if(t%i==0){
                int c=0;
                while(t%i==0){
                    t/=i;c++;
                }
                ans=(ans*(binpow(c+1,n)-2*binpow(c,n)+binpow(c-1,n)))%MOD;
            }
        if(t!=1)
            ans=(ans*(binpow(2,n)-2))%MOD;
        printf("%lld\n",(ans%MOD+MOD)%MOD);
    }
    return 0;
}