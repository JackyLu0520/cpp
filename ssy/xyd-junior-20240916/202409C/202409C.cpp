#include<bits/stdc++.h>
using namespace std;
const int N=16;
long long n,k,pow7[N],x,ans;
int main(){
    freopen("202409C.in","r",stdin);
    freopen("202409C.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    pow7[0]=1;
    for(int i=1;i<=n;i++)
        pow7[i]=7*pow7[i-1];
    x=(1<<n)-k;
    for(int i=0;x;i++){
        if(x&1) ans+=pow7[i];
        x>>=1;
    }
    printf("%lld",ans);
    return 0;
}