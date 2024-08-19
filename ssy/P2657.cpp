#include<bits/stdc++.h>
using namespace std;
const long long L=10;
long long a,b,dp[L+5][10];
void init(){
    for(int i=0;i<10;i++)   dp[1][i]=1;
    for(int i=2;i<=L;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                if(abs(j-k)>=2)
                    dp[i][j]+=dp[i-1][k];
}
long long solve(long long x){
    long long c[L+5],len=0,ans=0;
    while(x){
        c[++len]=x%10;x/=10;
    }
    for(int i=1;i<=len-1;i++)
        for(int j=1;j<10;j++)
            ans+=dp[i][j];
    for(int i=1;i<c[len];i++)
        ans+=dp[len][i];
    for(int i=len-1;i>=1;i--){
        for(int j=0;j<=c[i]-1;j++)
            if(abs(j-c[i+1])>=2)    ans+=dp[i][j];
        if(abs(c[i]-c[i+1])<2) break;
    }
    return ans;
}
int main(){
    scanf("%lld%lld",&a,&b);
    init();
    printf("%lld",solve(b+1)-solve(a));
    return 0;
}