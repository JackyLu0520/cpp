#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,q;
long long a[N];
long long b[N],r[N],s[N],id=0;
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)
        a[i]=a[i]&1;
    for(long long i=1;i<=n;){
        long long k=i;
        id++;
        while(k<n&&a[k]==a[k+1]) b[k++]=id;
        r[id]=k;s[id]=s[id-1]+(k-i+2)*(k-i+1)/2;b[k]=id;
        i=k+1;
    }
    while(q--){
        long long i,j;scanf("%lld%lld",&i,&j);
        long long ans=(j-i+2)*(j-i+1)/2;
        if(b[i]==b[j]){ans=0;printf("%lld\n",ans);continue;}
        ans-=s[b[j]-1]-s[b[i]];
        ans-=(r[b[i]]-i+2)*(r[b[i]]-i+1)/2;
        ans-=(j-r[b[j]-1]+1)*(j-r[b[j]-1])/2;
        printf("%lld\n",ans);
    }
    return 0;
}