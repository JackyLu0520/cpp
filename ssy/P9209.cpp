#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,w[N],l[N],r[N];
long long ans=0;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&l[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&r[i]);
    for(int i=1;i<=n;i++)
        ans+=w[i]-max(l[i],r[i])*(n-i);
    printf("%lld",ans);
    return 0;
}