#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,d,cnt=0;
int main(){
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
    for(long long x=1;x<=n;x++)
        if(a+x-d>=1&&a+x-d<=n&&
           c+x-b>=1&&c+x-b<=n&&
           a+c+x-b-d>=1&&a+c+x-b-d<=n)
            cnt++;
    printf("%lld",cnt*n);
    return 0;
}