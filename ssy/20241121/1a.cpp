#include<bits/stdc++.h>
#define lowbit(x) (x)&(-(x))
using namespace std;
const int N=1e5+10,MOD=998244353;
int n,a[N];
struct BIT{
    long long c[N];
    void clear(){
        memset(c,0,sizeof(c));
    }
    void add(int i,long long k){
        for(;i<=n;i+=lowbit(i))
            c[i]=(c[i]+k)%MOD;
    }
    long long query(int i){
        long long ans=0;
        for(;i;i-=lowbit(i))
            ans=(ans+c[i])%MOD;
        return ans;
    }
}bit1,bit2;
long long dp1[N],dp2[N];
long long ans;
int main(){
    int _;scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        bit1.clear();
        bit2.clear();
        memset(dp1,0,sizeof dp1);
        memset(dp2,0,sizeof dp2);
        ans=0;
        for(int i=n;i>=1;i--){
            dp1[i]=(bit1.query(a[i]-1)+1)%MOD;
            dp2[i]=((bit2.query(n)-bit2.query(a[i])+1)%MOD+MOD)%MOD;
            bit1.add(a[i],dp1[i]);
            bit2.add(a[i],dp2[i]);
        }
        for(int i=1;i<=n;i++)
            ans=(ans+dp1[i]*dp2[i]%MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}