#include<bits/stdc++.h>
using namespace std;
const int K=1e6+10;
int n,m,k,r[K]={0},c[K]={0};
long long ans=0;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=k;j+=i)
            r[j]++;
    for(int i=1;i<=m;i++)
        for(int j=i;j<=k;j+=i)
            c[j]++;
    for(int i=1;i<=k;i++)
        ans+=1LL*i*r[i]*c[i];
    printf("%lld",ans);
    return 0;
}