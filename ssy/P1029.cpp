#include<bits/stdc++.h>
using namespace std;
long long x0,y0;
long long gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
long long ans=0;
int main(){
    scanf("%lld%lld",&x0,&y0);
    long long i;
    for(i=1;i*i<x0*y0;i++)
        if((x0*y0)%i==0&&gcd(i,x0*y0/i)==x0)
            ans+=2;
    if(i*i==x0*y0)  ans++;
    printf("%d",ans);
    return 0;
}