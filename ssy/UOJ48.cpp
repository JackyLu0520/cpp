#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
long long a[N];
long long p[N],pp=0;
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
void prework(){
    long long t=a[1];
    for(long long i=2;i*i<=t;i++)
        if(t%i==0){
            p[++pp]=i;
            while(t%i==0)   t/=i;
        }
    if(t)   p[++pp]=t;
}
long long sgcd_a1(long long b){
    long long d=gcd(a[1],b);
    if(d==1) return -1;
    for(int i=1;i<=pp;i++)
        if(d%p[i]==0)
            return d/p[i];
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    prework();
    for(int i=1;i<=n;i++)
        printf("%lld ",sgcd_a1(a[i]));
    return 0;
}