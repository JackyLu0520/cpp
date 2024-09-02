#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;scanf("%lld",&t);
    while(t--){
        long long n;scanf("%lld",&n);
        printf("%lld\n",n==1?1:n*(n-1));
    }
    return 0;
}