#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110,M=110,MOD=1e9+7;
int n,m;
int dp[N][M][M],s[M][M];
int a[N][M],ans;
inline void mod(int &x){
    x=(x%MOD+MOD)%MOD;
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++){
            char c;
            scanf(" %c",&c);
            a[i][j]=a[i][j-1]+(c=='X');
        }
    dp[0][1][m]=1;ans++;
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++)
            for(int r=1;r<=m;r++){
                s[l][r]=dp[i-1][l][r]+s[l][r-1]+s[l-1][r]-s[l-1][r-1];
                mod(s[l][r]);
            }
        for(int l=1;l<=m;l++)
            for(int r=l;r<=m;r++)
                if(a[i][l-1]==a[i][r]){
                    dp[i][l][r]=s[l][m]-s[l][r-1];
                    mod(dp[i][l][r]);
                    ans+=dp[i][l][r];
                    mod(ans);
                }
    }
    printf("%lld",ans);
    return 0;
}