#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;scanf("%lld",&t);
    while(t--){
        long long n,p;
        scanf("%lld%lld",&n,&p);
        if(p==1){printf("0\n");continue;}
        long long ans=0;
        for(long long s=1;n>0;s=-s,n/=p)
            ans+=s*n;
        printf("%lld\n",ans);
    }
    return 0;
}