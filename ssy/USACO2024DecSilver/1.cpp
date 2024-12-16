#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        long long n,a[N];
        long long sum=0,now=0,d,ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        d=sum;
        for(int i=1;i<=n/2+1;i++)
            now+=a[i];
        for(int i=n/2+2;i<=n+1;i++){
            if(llabs(sum-now-now)<d){
                ans=now;d=llabs(sum-now-now);
            }
            now+=a[i];
            now-=a[i-(n/2+1)];
        }
        printf("%lld %lld\n",ans,sum-ans);
    }
    return 0;
}