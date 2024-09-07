#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2010;
const ll MOD=1e9+7;
int n,cnt[26]={0};
ll fact[N],ans=0;
ll binpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
int main(){
    char s[N];
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
        cnt[s[i]-'a']++;
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=(i*fact[i-1])%MOD;
    ans=fact[n];
    int f=0;
    for(int i=0;i<26;i++)
        f+=cnt[i]%2;
    if((n%2&&f==1)||(!(n%2)&&f==0)){
        ll t=fact[n/2];
        for(int i=0;i<26;i++){
            t=(t*fact[cnt[i]/2*2])%MOD;
            t=(t*binpow(fact[cnt[i]/2],MOD-2))%MOD;
            if(cnt[i]%2)
                t=(t*cnt[i])%MOD;
        }
        ans=(ans-t)%MOD;
    }
    ans=(ans%MOD+MOD)%MOD;
    printf("%lld",ans);
    return 0;
}