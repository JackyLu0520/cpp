#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e5+3;
long long m,n;
long long binpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld%lld",&m,&n);
    printf("%lld",((binpow(m,n)-(m*binpow(m-1,n-1))%MOD)%MOD+MOD)%MOD);
    return 0;
}