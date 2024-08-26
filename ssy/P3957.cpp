#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,d,k,x[N],s[N],dp[N];
bool check(int g){
    memset(dp,~0x3f,sizeof(dp));dp[0]=0;
    for(int i=1;i<=n;i++){
        int l=lower_bound(x,x+i,max(x[i]-d-g,0))-x;
        int r=upper_bound(x,x+i,min(x[i]-d+g,x[i]))-x;
        for(int j=l;j<r;j++)
            dp[i]=max(dp[i],dp[j]+s[i]);
    }
    int Max=-0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        Max=max(Max,dp[i]);
    return Max>=k;
}
int main(){
    scanf("%d%d%d",&n,&d,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&s[i]);
    int l=0,r=max(x[n],d);
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))  r=mid;
        else            l=mid+1;
    }
    printf("%d",l==max(x[n],d)?-1:l);
    return 0;
}