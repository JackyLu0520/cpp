#include<bits/stdc++.h>
#define int long long
using namespace std;
const double eps=1e-9;
const int N=1e5+10;
int n,k;
int a[N],s[N];
double b[N],f[N];
bool check(double x){
    for(int i=1;i<=n;i++)
        b[i]=s[i]-x*i;
    if(b[n]<-eps)  return 0;
    f[0]=0;int len=0;
    for(int i=1;i<n;i++){
        if(b[i]-b[n]>eps||b[i]<-eps)   continue;
        if(b[i]-f[len]>-eps)    f[++len]=b[i];
        else                    *upper_bound(f+1,f+len+1,b[i])=b[i];
    }
    return len+1>=k;
}
signed main(){
    freopen("data.in","r",stdin);
    freopen("sol.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--){
        double l=0,r=0;
        scanf("%lld%lld",&n,&k);
        s[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            s[i]=s[i-1]+a[i];
            r=max(r,1.0*a[i]);
        }
        while(r-l>=eps){
            double mid=(l+r)/2;
            if(check(mid))  l=mid;
            else            r=mid;
        }
        printf("%lf\n",l);
    }
    return 0;
}