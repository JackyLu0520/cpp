#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;
char s[N];
int dp[N][N];
inline bool match(char a,char b){
    return a=='('&&b==')'||a=='['&&b==']';
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%s",s+1);
        n=strlen(s+1);
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[i][i]=1;
        for(int j=1;j<=n;j++)
            for(int i=j-1;i>=1;i--){
                if(match(s[i],s[j]))
                    dp[i][j]=dp[i+1][j-1];
                for(int k=i;k<j;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}