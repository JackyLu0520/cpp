#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n;
int dp[N][1<<3];
int main(){
    cin>>n;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        int c,s=0;
        char str[5];
        scanf("%d%s",&c,str);
        for(int j=0;j<strlen(str);j++)
            s|=(1<<(str[j]-'A'));
        for(int j=0;j<(1<<3);j++)
            dp[i][j]=dp[i-1][j];
        for(int j=0;j<(1<<3);j++)
            dp[i][j|s]=min(dp[i][j|s],dp[i-1][j]+c);
    }
    printf("%d\n",dp[n][(1<<3)-1]==0x3f3f3f3f?-1:dp[n][(1<<3)-1]);
    return 0;
}