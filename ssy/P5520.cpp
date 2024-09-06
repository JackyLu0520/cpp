#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p;
ll A(ll a,ll b){
    ll ans=1;
    for(ll i=a;i>=a-b+1;i--)
        ans=(ans*i)%p;
    return ans;
}
int main(){
    scanf("%*lld%lld%lld%lld",&n,&m,&p);
    printf("%lld",A(n-m+1,m));
    return 0;
}