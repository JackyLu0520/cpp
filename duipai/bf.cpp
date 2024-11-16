#include<bits/stdc++.h>
using namespace std;
const int N=1.5e5+10;
long long n,a[N],b[N],q;
int main(){
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    scanf("%lld",&q);
    while(q--){
        long long x,y;scanf("%lld%lld",&x,&y);
        for(int i=1;i<=n;i++)
            b[i]=a[i];
        b[x]=y;
        sort(b+1,b+n+1);
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans+=i*b[i];
        printf("%lld\n",ans);
    }
    return 0;
}