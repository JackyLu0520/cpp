#include<bits/stdc++.h>
using namespace std;
const long long MOD=19260817;
long long read()
{
    long long x=0;
    char c=getchar();
    while(c<'0'||c>'9')   c=getchar();
    while(c>='0'&&c<='9')
        x=(x*10+c-'0')%MOD,c=getchar();
    return x;
}
long long a,b;
long long binpow(long long x,long long y,long long p){
    long long ans=1;
    while(y){
        if(y&1) ans=(ans*x)%p;
        x=(x*x)%p;
        y>>=1;
    }
    return ans;
}
int main(){
    a=read(),b=read();
    printf("%lld",(a*binpow(b,MOD-2,MOD))%MOD);
    return 0;
}