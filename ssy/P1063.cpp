#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[2*N],dp[2*N][2*N],ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[n+i]=a[i];
    for(int j=2;j<=2*n-1;j++)
        for(int i=j-1;i>=1;i--){
            dp[i][j]=0;
            for(int k=i;k<j;k++)
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i][n+i-1]);
    printf("%d",ans);
    return 0;
}