#include<bits/stdc++.h>
using namespace std;
long long x,y;
long long gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
long long ans=0;
int main(){
    scanf("%lld%lld",&x,&y);
    if(y%x!=0){printf("0");return 0;}
    if(x==y){printf("1");return 0;}
    long long i;
    for(i=1;i*i<x*y;i++)
        if((x*y)%i==0&&gcd(i,x*y/i)==x)
            ans+=2;
    printf("%d",ans);
    return 0;
}