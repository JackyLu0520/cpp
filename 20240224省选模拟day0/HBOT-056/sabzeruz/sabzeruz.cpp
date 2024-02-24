#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,MOD=1e9+7;
const long long INF=0x7fffffffffffffff;
int n,ans=0;
long long a[N],k1,k2;
long long a1[N],tot1=0;
long long a2[N],tot2=0;
void dfs(int x){
    if(x>n){
        long long min1=INF,min2=INF;
        for(int i=1;i<tot1;i++)
            min1=min(min1,a1[i]^a1[i+1]);
        for(int i=1;i<tot2;i++)
            min2=min(min2,a2[i]^a2[i+1]);
        if(min1>=k1&&min2>=k2)
            ans=(ans+1)%MOD;
        return;
    }
    a1[++tot1]=a[x];
    dfs(x+1);
    tot1--;
    a2[++tot2]=a[x];
    dfs(x+1);
    tot2--;
}
int main(){
    scanf("%d%lld%lld",&n,&k1,&k2);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    dfs(1);
    printf("%d",ans);
    return 0;
}