#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n;
bool notp[N];
signed main(){
    scanf("%lld",&n);
    for(int i=2;i<=n;i++)
        if(!notp[i]){
            for(int j=i+i;j<=n;j+=i)
                notp[j]=1;
            int t=i,cnt=0;
            while(t<=n){
                cnt+=n/t;
                t*=i;
            }
            printf("%lld %lld\n",i,cnt);
        }
    return 0;
}