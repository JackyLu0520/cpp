#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=255,W=1e3+10;
int n,v,w[N],t[N];
bool check(int x){
    int a[N];
    for(int i=1;i<=n;i++)
        a[i]=t[i]-x*w[i];
    int dp[W];
    memset(dp,~0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=v;j>=0;j--)
            if(dp[j]!=-0x3f3f3f3f3f3f3f3f){
                int t=min(j+w[i],v);
                dp[t]=max(dp[t],dp[j]+a[i]);
            }
    /*for(int i=0;i<=n;i++)
        printf("%lld ",a[i]);
    printf("\n");
    for(int i=0;i<=v;i++)
        printf("%lld ",dp[i]);
    printf("\n");*/
    return dp[v]>=0;
}
signed main(){
    scanf("%lld%lld",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&w[i],&t[i]);
    for(int i=1;i<=n;i++)
        t[i]*=1000;
    int l=0,r=0x3f3f3f3f;
    while(l<r){
        int mid=(l+r+1)/2;
        //printf("%lld %lld %lld %lld\n",l,r,mid,check(mid));
        if(check(mid))  l=mid;
        else            r=mid-1;
    }
    printf("%lld",l);
    return 0;
}