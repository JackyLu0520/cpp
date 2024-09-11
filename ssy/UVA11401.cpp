#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        long long n;
        scanf("%lld",&n);
        if(n<3) break;
        printf("%lld\n",((n-1)*(n-2)*(2*n-3)-6*((n-1)/2))/24);
    }
    return 0;
}