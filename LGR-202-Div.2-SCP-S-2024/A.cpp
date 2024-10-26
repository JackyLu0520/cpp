#include<bits/stdc++.h>
using namespace std;
constexpr int L=1e5+10;
int main(){
    int t;scanf("%*d%d",&t);
    while(t--){
        char n[L];scanf("%s",n+1);
        int len=strlen(n+1);
        long long v[10];
        for(int i=1;i<=9;i++)
            scanf("%lld",&v[i]);
        long long dp1[L],dp2[L];
        dp1[0]=dp2[0]=0;
        for(int i=1;i<=len;i++)
            if(dp1[i-1]+dp2[i-1]+v[n[i]-'0']<=dp1[i-1]+dp2[i-1]*10+(n[i]-'0')){
                dp1[i]=dp1[i-1]+v[n[i]-'0'];
                dp2[i]=dp2[i-1];
            }else{
                dp1[i]=dp1[i-1];
                dp2[i]=dp2[i-1]*10+(n[i]-'0');
            }
        printf("%lld\n",dp1[len]+dp2[len]);
    }
    return 0;
}