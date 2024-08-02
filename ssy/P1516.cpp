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
    ll x,y,m,n,l;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    ll a=m-n,b=l,c=y-x,x0,y0;
    if(a<0) a=-a,c=-c;
    ll d=exgcd(a,b,x0,y0);
    if(c%d) printf("Impossible");
    else    printf("%lld",((x0*(c/d))%(b/d)+(b/d))%(b/d));
    return 0;
}