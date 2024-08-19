#include<bits/stdc++.h>
using namespace std;
int n,m,now,pre;
long long dp[2][1<<11];
int main(){
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)  break;
        if(m>n) swap(m,n);
        memset(dp,0,sizeof(dp));
        now=0;pre=1;
        dp[now][(1<<m)-1]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                swap(now,pre);
                memset(dp[now],0,sizeof(dp[now]));
                for(int k=0;k<(1<<m);k++){
                    if(k&(1<<(m-1)))
                        dp[now][(k<<1)&(~(1<<m))]+=dp[pre][k];
                    if(i&&!(k&(1<<(m-1))))
                        dp[now][(k<<1)^1]+=dp[pre][k];
                    if(j&&(!(k&1))&&(k&(1<<(m-1))))
                        dp[now][((k<<1)|3)&(~(1<<m))]+=dp[pre][k];
                }
            }
        printf("%lld\n",dp[now][(1<<m)-1]);
    }
    return 0;
}