#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,d,k,x[N],s[N],dp[N];
bool check(int g){
    memset(dp,~0x3f,sizeof(dp));dp[0]=0;
    deque<int>q;
    int r=0;
    for(int i=1;i<=n;i++){
        /*int l=lower_bound(x,x+i,max(x[i]-d-g,0))-x;
        int r=upper_bound(x,x+i,min(x[i]-d+g,x[i]))-x;
        for(int j=l;j<r;j++)
            dp[i]=max(dp[i],dp[j]+s[i]);*/
        while(x[r]<=x[i]-d+g&&r<i){
            while(!q.empty()&&dp[r]>dp[q.back()]) q.pop_back();
            q.push_back(r);r++;
        }
        while(!q.empty()&&x[q.front()]<x[i]-d-g)q.pop_front();
        if(!q.empty())dp[i]=dp[q.front()]+s[i];
    }
    int Max=-0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++)
        Max=max(Max,dp[i]);
    return Max>=k;
}
signed main(){
    scanf("%lld%lld%lld",&n,&d,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&x[i],&s[i]);
    int l=0,r=max(x[n],d);
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))  r=mid;
        else            l=mid+1;
    }
    printf("%lld",l==max(x[n],d)?-1:l);
    return 0;
}