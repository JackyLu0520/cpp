//x=k*sqrt(c)-t
//a^(k*sqrt(c))===b*a^t(mod c)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;//a^x===b(mod c)
ll rtc,apowrtc=1;
unordered_map<ll,ll>mp;
int main(){
    scanf("%lld%lld%lld",&c,&a,&b);
    rtc=ceil(sqrt(c));
    for(ll i=1;i<=rtc;i++)
        apowrtc=(apowrtc*a)%c;
    ll tmp=b;
    for(ll i=1;i<=rtc;i++){
        tmp=(tmp*a)%c;
        mp[tmp]=i;
    }
    tmp=1;
    for(ll i=1;i<=rtc;i++){
        tmp=(tmp*apowrtc)%c;
        if(mp.count(tmp)){
            ll ans=i*rtc-mp[tmp];
            printf("%lld",ans);
            return 0;
        }
    }
    printf("no solution");
    return 0;
}