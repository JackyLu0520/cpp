#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],dp[1000010],ans=0;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int maxdp=0;
        for(int j=1;j<i;j++)
            if(gcd(a[i],a[j])>1)
                maxdp=max(maxdp,dp[j]);
        dp[i]=maxdp+1;
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}