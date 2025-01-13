#include<bits/stdc++.h>
using namespace std;
const int N=310;
int n;
char s[N];
int dp[N][N];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int j=1;j<=n;j++)
        for(int i=j-1;i>=1;i--){
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                if(s[i]=='i'&&s[j]=='i'&&s[k]=='w'&&dp[i+1][k-1]==k-i-1&&dp[k+1][j-1]==j-k-1)
                    dp[i][j]=j-i+1;
            }
        }
    printf("%d\n",dp[1][n]/3);
    return 0;
}