#include<bits/stdc++.h>
using namespace std;
const int N=85,M=85;
int n,m,a[M];
__int128 pow2[M],dp[M][M],ans=0;
__int128 max(__int128 a,__int128 b){
    return a<b?b:a;
}
void print(__int128 x){
    if(x==0)    printf("0");
    int a[130],p=0;
    while(x)    a[++p]=x%10,x/=10;
    for(int i=p;i>=1;i--)   printf("%d",a[i]);
}
int main(){
    scanf("%d%d",&n,&m);
    pow2[0]=1;
    for(int i=1;i<=m;i++)
        pow2[i]=pow2[i-1]*2;
    while(n--){
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                dp[i][j]=0;
        for(int i=1;i<=m;i++)
            for(int j=m;j>=i;j--){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i-1]*pow2[m-j+i-1]);
                dp[i][j]=max(dp[i][j],dp[i][j+1]+a[j+1]*pow2[m-j+i-1]);
            }
        __int128 Max=0;
        for(int i=1;i<=m;i++)
            Max=max(Max,dp[i][i]+a[i]*pow2[m]);
        ans+=Max;
    }
    print(ans);
    return 0;
}