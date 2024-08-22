#include<bits/stdc++.h>
using namespace std;
const int N=55,INF=0x3f3f3f3f;
char s[N];
int n,dp[N][N];
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=1;i<=n;i++)   dp[i][i]=1;
    for(int j=2;j<=n;j++)
        for(int i=j-1;i>=1;i--){
            dp[i][j]=INF;
            if(s[i]==s[j])  dp[i][j]=dp[i+1][j];
            else
                for(int k=i;k<j;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    printf("%d",dp[1][n]);
    return 0;
}