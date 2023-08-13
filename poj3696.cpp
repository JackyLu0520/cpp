#include<cstdio>
using namespace std;
typedef long long ll;
ll id=0;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll phi(ll n){
    ll res=n;
    for(int i=1;i*i<=n;i++)
        if(n%i==0){
            res=res/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    if(n>1) res=res/n*(n-1);
    return res;
}
ll binmul(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
ll binmul(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=binmul(res,a,mod);
        a=binmul(a,a,mod);
        b>>=1;
    }
    return res;
}
int main(){
    while(1){
        ll L;
        scanf("%lld",L);
        if(!L)  break;
        printf("Case %lld",++id);
        ll d=gcd(l,8);
        if(gcd(L/d*9,10)>1){printf("0");continue;}

    }
}