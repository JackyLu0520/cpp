#include<bits/stdc++.h>
using namespace std;
long long n;int k;
long long C(int a,int b){//C_a^b
    long long ans=1;
    for(int i=1;i<=b;i++)
        ans=ans*(a-i+1)/i;
    return ans;
}
int main(){
    long long ans=0;
    scanf("%lld%d",&n,&k);
    n++;
    for(int i=62;i>=0&&k>=0;i--)
        if(n&(1LL<<i)){
            //printf("C_%d^%d=%lld\n",i,k,C(i,k));
            ans+=C(i,k),k--;
        }
    printf("%lld",ans);
    return 0;
}