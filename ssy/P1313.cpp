#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e4+7,K=1010;
int a,b,k,n,m,ans;
int C[K][K];
int binpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=(ans*x)%MOD;
        x=(x*x)%MOD;
        y>>=1;
    }
    return ans;
}
signed main(){
    scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
    ans=(binpow(a,n)*binpow(b,m))%MOD;
    for(int i=0;i<=k;i++)
        C[i][0]=C[i][i]=1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    ans=(ans*C[k][n])%MOD;
    printf("%lld",ans);
    return 0;
}