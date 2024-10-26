#include<bits/stdc++.h>
using namespace std;
long long n,k,sum;
int main(){
    scanf("%lld%lld",&n,&k);
    for(long long l=1,r;l<=n;l=r+1){
        if(k/l!=0)  r=min(k/(k/l),n);
        else        r=n;
        sum+=(k/l)*(l+r)*(r-l+1)/2;
        //printf("%lld~%lld:%lld\n",l,r,k/r);
    }
    printf("%lld\n",n*k-sum);
    return 0;
}