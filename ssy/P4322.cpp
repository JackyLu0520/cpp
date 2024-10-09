#include<bits/stdc++.h>
using namespace std;
constexpr int N=2510;
constexpr double eps=1e-6;
int n,k,s[N],p[N],fa[N];
double dp[N][N];
int sz[N];
bool check(double x){
    for(int i=0;i<=n;i++)
        for(int j=1;j<=k+1;j++)
            dp[i][j]=-1e9;
    for(int i=0;i<=n;i++){
        dp[i][1]=p[i]-x*s[i];
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++)
        sz[i]=1;
    for(int i=n;i>=0;i--)
        sz[fa[i]]+=sz[i];
    for(int i=n;i>=1;i--){
        int u=fa[i],v=i;
        for(int j=min(sz[u],k+1);j>=1;j--)
            for(int k=0;k<=min(sz[v],j-1);k++)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
    return dp[0][k+1]>=0;
}
int main(){
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&s[i],&p[i],&fa[i]);
    double l=0,r=0;
    for(int i=1;i<=n;i++)
        r+=p[i];
    while(fabs(r-l)>=eps){
        double mid=(l+r)/2;
        //printf("%.3lf %.3lf %.3lf\n",l,r,mid);
        if(check(mid))  l=mid;
        else            r=mid;
    }
    printf("%.3lf",l);
    return 0;
}