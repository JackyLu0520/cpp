#include<bits/stdc++.h>
using namespace std;
const int N=19;
const double eps=1e-6;
int n;
double x[N],y[N];
int l[N][N],dp[1<<N];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%*d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        memset(l,0,sizeof(l));
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(fabs(x[i]-x[j])<eps) continue;
                double a=(x[j]*y[i]-x[i]*y[j])/(x[i]*x[i]*x[j]-x[j]*x[j]*x[i]);
                double b=(x[j]*x[j]*y[i]-x[i]*x[i]*y[j])/(x[i]*x[j]*x[j]-x[j]*x[i]*x[i]);
                if(a>-eps)  continue;
                for(int k=1;k<=n;k++)
                    if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<eps)
                        l[i][j]|=1<<(k-1);
                //clog<<"l["<<i<<"]["<<j<<"]:"<<a<<"x^2+"<<b<<"x,"<<bitset<32>(l[i][j])<<endl;
            }
        for(int i=0;i<(1<<n);i++){
            int j=(~i)&(-(~i))&(~(1<<n));
            dp[i|j]=min(dp[i|j],dp[i]+1);
            for(int k=1;k<=n;k++){
                //clog<<bitset<32>(i|l[__builtin_ctz(j)+1][k])<<":"<<dp[i|l[__builtin_ctz(j)+1][k]]<<"<-"<<bitset<32>(i)<<":"<<dp[i]<<endl;
                dp[i|l[__builtin_ctz(j)+1][k]]=min(dp[i|l[__builtin_ctz(j)+1][k]],dp[i]+1);
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}