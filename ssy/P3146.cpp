#include<bits/stdc++.h>
using namespace std;
const int N=250;
int n,dp[N][N],ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&dp[i][i]);
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i][i]);
    for(int j=2;j<=n;j++)
        for(int i=j-1;i>=1;i--)
            for(int k=i;k<j;k++)
                if((dp[i][k]==dp[k+1][j])&&dp[i][k]){
                    dp[i][j]=max(dp[i][j],dp[i][k]+1);
                    ans=max(ans,dp[i][j]);
                }
    printf("%d",ans);
    return 0;
}