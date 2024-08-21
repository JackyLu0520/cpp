#include<bits/stdc++.h>
using namespace std;
const int N=110,M=7,MOD=1e9+7;
int n,m,now=0,pre=1;
long long dp[2][1<<M][1<<M],ans=0;
bool check1(int j,int k){
    for(int i=0;i<m;i++){
        if(i<m-2&&(j&(1<<i))&&(k&(1<<(i+2)))&&!(j&(1<<(i+1)))&&!(k&(1<<(i+1))))
            return 0;
        if(i>1&&(j&(1<<i))&&(k&(1<<(i-2)))&&!(j&(1<<(i-1)))&&!(k&(1<<(i-1))))
            return 0;
    }
    return 1;
}
bool check2(int j,int k,int l){
    for(int i=0;i<m;i++){
        if(i<m-1&&(j&(1<<i))&&(l&(1<<(i+1)))&&!(k&(1<<i))&&!(k&(1<<(i+1))))
            return 0;
        if(i>0&&(j&(1<<i))&&(l&(1<<(i-1)))&&!(k&(1<<i))&&!(k&(1<<(i-1))))
            return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    dp[now][0][0]=1;
    for(int i=2;i<=n+1;i++){
        swap(now,pre);
        memset(dp[now],0,sizeof(dp[now]));
        for(int j=0;j<(1<<m);j++)
            for(int k=0;k<(1<<m);k++)
                if(check1(j,k))
                    for(int l=0;l<(1<<m);l++)
                        if(check2(j,k,l)&&check1(k,l))
                            dp[now][j][k]=(dp[now][j][k]+dp[pre][k][l])%MOD;
    }
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++)
            ans=(ans+dp[now][i][j])%MOD;
    printf("%lld",ans);
    return 0;
}