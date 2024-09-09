#include<bits/stdc++.h>
using namespace std;
const int S=1e5+10;
int c[5],d[5],n,s;
long long dp[S];
int main(){
    for(int i=1;i<=4;i++)
        scanf("%d",&c[i]);
    dp[0]=1;
    for(int i=1;i<=4;i++)
        for(int j=c[i];j<S;j++)
            dp[j]+=dp[j-c[i]];
    scanf("%d",&n);
    while(n--){
        for(int i=1;i<=4;i++)
            scanf("%d",&d[i]);
        scanf("%d",&s);
        long long ans=0;
        for(int i=0;i<=15;i++){
            int t=s;
            for(int j=1;j<=4;j++)
                if(i&(1<<(j-1)))
                    t-=c[j]*(d[j]+1);
            if(t<0) continue;
            if(__builtin_parity(i))
                ans-=dp[t];
            else
                ans+=dp[t];
        }
        printf("%lld\n",ans);
    }
    return 0;
}