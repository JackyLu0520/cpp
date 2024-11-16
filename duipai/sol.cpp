#include<bits/stdc++.h>
using namespace std;
const int N=1.5e5+10;
long long n,a[N],b[N],s[N],sum=0,q;
int main(){
    freopen("data.in","r",stdin);
    freopen("sol.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+b[i];
        sum+=i*b[i];
    }
    //debug
    /*for(int i=1;i<=n;i++)
        printf("%lld ",b[i]);
    printf("\n");
    for(int i=1;i<=n;i++)
        printf("%lld ",s[i]);
    printf("\n");
    printf("%lld\n",sum);*/
    //
    scanf("%lld",&q);
    while(q--){
        long long x,y;scanf("%lld%lld",&x,&y);
        long long q=lower_bound(b+1,b+n+1,a[x])-b;
        b[q]=b[q-1];
        long long p=upper_bound(b+1,b+n+1,y)-b-1;
        b[q]=a[x];
        //debug
        //printf("%lld %lld ",p,q);
        //
        if(p>q)
            printf("%lld\n",sum-(s[p]-s[q])+y*p-q*a[x]);
        else if(p==q)
            printf("%lld\n",sum-q*a[x]+p*y);
        else
            printf("%lld\n",sum+(s[q-1]-s[p])+y*(p+1)-q*a[x]);
    }
    return 0;
}