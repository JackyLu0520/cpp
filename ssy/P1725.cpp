#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,l,r,a[2*N],dp[2*N],ans=-0x3f3f3f3f;
deque<int>q;
int main(){
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,~0x3f,sizeof dp);dp[0]=a[0];
    for(int i=0;i<=n;i++){
        while(!q.empty()&&dp[q.back()]<dp[i])  q.pop_back();
        q.push_back(i);
        while(!q.empty()&&i-q.front()>r-l)  q.pop_front();
        dp[i+l]=dp[q.front()]+a[i+l];
    }
    for(int i=n+1;i<=2*n;i++)   ans=max(ans,dp[i]);
    printf("%d",ans+a[0]);
    return 0;
}