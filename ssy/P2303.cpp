#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
    scanf("%lld",&n);
    ans=n;
    for(long long i=2;i*i<=n;i++)
        if(n%i==0){
            long long c=0;
            while(n%i==0)   n/=i,c++;
            ans/=i;ans*=i*c-c+i;
        }
    if(n>1) ans/=n,ans*=n+n-1;
    printf("%lld",ans);
    return 0;
}