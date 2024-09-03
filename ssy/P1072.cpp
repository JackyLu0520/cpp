#include<bits/stdc++.h>
using namespace std;
long long n;
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
long long lcm(long long a,long long b){
    return a/gcd(a,b)*b;
}
int main(){
    scanf("%lld",&n);
    while(n--){
        long long a0,a1,b0,b1;
        long long cnt=0,i;
        scanf("%lld%lld%lld%lld",&a0,&a1,&b0,&b1);
        for(i=1;i*i<b1;i++)
            if(b1%i==0){
                if(i%a1==0&&gcd(i,a0)==a1&&lcm(i,b0)==b1)
                    cnt++;
                if((b1/i)%a1==0&&gcd(b1/i,a0)==a1&&lcm(b1/i,b0)==b1)
                    cnt++;
            }
        if(i*i==b1&&i%a1==0&&gcd(i,a0)==a1&&lcm(i,b0)==b1)
            cnt++;
        printf("%lld\n",cnt);
    }
    return 0;
}