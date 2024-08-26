#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,c,a[N],lmax[N],rmax[N],s[N];
signed main(){
    int t;scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&c);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        s[0]=lmax[0]=a[0]=0;rmax[n+1]=a[n+1]=0;a[1]+=c;
        for(int i=1;i<=n;i++)
            lmax[i]=max(lmax[i-1],a[i]);
        for(int i=n;i>=1;i--)
            rmax[i]=max(rmax[i+1],a[i]);
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+a[i];
        for(int i=1;i<=n;i++){
            if(lmax[i-1]<a[i]){
                if(rmax[i+1]<=a[i]) printf("0 ");
                else{
                    if(s[i]>=rmax[i+1]) printf("%lld ",i-1);
                    else                printf("%lld ",i);
                }
            }else{
                if(s[i]>=rmax[i+1]) printf("%lld ",i-1);
                else                printf("%lld ",i);
            }
        }
        printf("\n");
    }
    return 0;
}