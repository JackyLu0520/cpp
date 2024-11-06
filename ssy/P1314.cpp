#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=2e5+10;
int n,m,s;
int w[N],v[N];
int L[M],R[M];
int y(int x){
    int s[N]={0},sv[N]={0};
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(w[i]>=x);
        sv[i]=sv[i-1]+(w[i]>=x)*v[i];
    }
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=(s[R[i]]-s[L[i]-1])*(sv[R[i]]-sv[L[i]-1]);
    return ans;
}
signed main(){
    scanf("%lld%lld%lld",&n,&m,&s);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&w[i],&v[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld",&L[i],&R[i]);
    int l=0,r=1e6+10;
    while(l<r){
        int mid=(l+r)/2;
        if(y(mid)<=s)   r=mid;
        else            l=mid+1;
    }
    printf("%lld",min(s-y(l),y(l-1)-s));
    return 0;
}