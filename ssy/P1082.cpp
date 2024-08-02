#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,x,y);
    ll z=x;x=y;y=z-y*(a/b);
    return d;
}
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    ll x,y;
    ll d=exgcd(a,b,x,y);
    printf("%lld",(x%b+b)%b);
    return 0;
}