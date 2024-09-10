#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,MOD=1e9+7;
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
    int n,a[N],vis[N]={0};bool f=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    if(n&1){
        if(vis[0]!=1)f=0;
        for(int i=2;i<=n;i+=2)
            if(vis[i]!=2)
                f=0;
    }else{
        for(int i=1;i<=n-1;i+=2)
            if(vis[i]!=2)
                f=0;
    }
    printf("%lld",f?binpow(2,n/2):0);
    return 0;
}