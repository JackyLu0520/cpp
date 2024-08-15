#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d%*s",&n);
        if(n==2){printf("1\n");continue;}
        if(n==3){printf("4\n");continue;}
        long long ans=1;
        for(int i=1;i<=n;i++)
            ans=(ans<<1)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}