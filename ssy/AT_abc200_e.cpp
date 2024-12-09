#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long C2(long long n){
    if(n<=0)    return 0;
    return n*(n-1)/2;
}
int main(){
    scanf("%lld%lld",&n,&x);
    for(long long i=3;i<=3*n;i++){
        long long t=C2(i-1)-3*C2(i-n-1)+3*C2(i-2*n-1)-C2(i-3*n-1);
        if(t<x) x-=t;
        else{
            for(long long j=max(1ll,i-2*n);j<=min(n,i-2);j++){
                int s=(i-j-1)-2*max(0ll,i-j-n-1)+max(0ll,i-j-2*n-1);
                if(s<x) x-=s;
                else{
                    printf("%lld %lld %lld",j,max(0ll,i-j-n-1)+x,i-j-x-max(0ll,i-j-n-1));
                    return 0;
                }
            }
        }
    }
    return 0;
}