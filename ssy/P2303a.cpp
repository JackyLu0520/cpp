#include<bits/stdc++.h>
using namespace std;
long long n;
long long phi(long long x){
    long long ans=x;
    for(long long i=2;i*i<=x;i++)
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0)   x/=i;
        }
    if(x!=1)    ans=ans/x*(x-1);
    return ans;
}
long long ans=0;
int main(){
    scanf("%lld",&n);
    for(long long i=1;i*i<=n;i++)
        if(n%i==0){
            ans+=i*phi(n/i);
            if(i!=n/i)  ans+=(n/i)*phi(i);
        }
    printf("%lld",ans);
    return 0;
}