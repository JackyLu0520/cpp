#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const long long MOD=1e9+7;
long long n;
bool notp[N]={0};
long long ans=1;
int main(){
    scanf("%lld",&n);
    for(int i=2;i<=n;i++){
        if(notp[i]) continue;
        for(int j=i;j<=n;j+=i)
            notp[j]=1;
        long long c=0,pow=i;
        while(pow<=n){
            c+=n/pow;
            pow*=i;
        }
        ans=(((c%MOD)*2+1)%MOD*ans)%MOD;
        //printf("%d %d\n",i,c);
    }
    printf("%lld",ans);
    return 0;
}