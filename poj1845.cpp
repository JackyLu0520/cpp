#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD=9901;
ll a,b,P[2000],C[2000]={0},pp=0;
ll binpow(ll x,ll y){
    ll res=1;
    while(y){
        x%=MOD;
        if(y&1) res=(res*x)%MOD;
        x*=x;
        y>>=1;
    }
    return res;
}
ll sum(ll p,ll c){
    if(!c)  return 1;
    if(c&1) return (((1+binpow(p,(c+1)>>1))%MOD)*(sum(p,(c-1)>>1))%MOD)%MOD;
    return (((((1+binpow(p,c>>1))%MOD)*((sum(p,(c>>1)-1))%MOD))%MOD)+binpow(p,c)%MOD)%MOD;
}
int main(){
    cin>>a>>b;
    ll t=a,ans=1;
    for(int i=2;i*i<=a;i++)
        if(t%i==0){
            P[++pp]=i;
            while(t%i==0){t/=i;C[pp]++;}
        }
    if(t!=1){P[++pp]=t;C[pp]=1;}
    /*for(int i=1;i<=pp;i++)
        cout<<P[i]<<' '<<C[i]<<'|';
    cout<<endl;*/
    for(int i=1;i<=pp;i++)
        ans=(ans*sum(P[i],b*C[i]))%MOD;
    cout<<ans;
    return 0;
}