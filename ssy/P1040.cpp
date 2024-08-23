#include<bits/stdc++.h>
using namespace std;
const int N=35;
long long n,a[N],dp[N][N];
int root[N][N];
void print(int l,int r){
    printf("%d ",root[l][r]);
    if(root[l][r]!=l)   print(l,root[l][r]-1);
    if(root[l][r]!=r)   print(root[l][r]+1,r);
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        dp[i][i]=a[i];
        root[i][i]=i;
    }
    for(int j=2;j<=n;j++)
        for(int i=j-1;i>=1;i--){
            if(dp[i+1][j]+a[i]>dp[i][j-1]+a[j]){
                dp[i][j]=dp[i+1][j]+a[i];
                root[i][j]=i;
            }else{
                dp[i][j]=dp[i][j-1]+a[j];
                root[i][j]=j;
            }
            for(int k=i+1;k<j;k++)
                if(dp[i][j]<dp[i][k-1]*dp[k+1][j]+a[k]){
                    dp[i][j]=dp[i][k-1]*dp[k+1][j]+a[k];
                    root[i][j]=k;
                }
        }
    printf("%lld\n",dp[1][n]);
    print(1,n);
    return 0;
}