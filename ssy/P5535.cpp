#include<bits/stdc++.h>
using namespace std;
long long n,k;
bool isprime(long long x){
    if(x==1)    return 0;
    for(long long i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main(){
    scanf("%lld%lld",&n,&k);
    if(isprime(k+1)&&2*(k+1)>n+1) printf("1");
    else                            printf("2");
    return 0;
}