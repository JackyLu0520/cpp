#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],dp[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dp[1]=a[1];dp[2]=a[2];
    for(int i=3;i<=n;i++)
        dp[i]=min(dp[i-1]+a[1]+a[i],dp[i-2]+a[1]+a[i]+2*a[2]);
    printf("%d",dp[n]);
    return 0;
}