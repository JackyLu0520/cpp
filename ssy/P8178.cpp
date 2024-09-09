#include<bits/stdc++.h>
#define int long long
using namespace std;
const int K=1e3+10;
void exgcd(int a,int b,int &x,int &y){
    if(!b){x=1,y=0;return;}
    exgcd(b,a%b,x,y);
    int z=x;x=y;y=z-(a/b)*y;
}
signed main(){
    int t;scanf("%lld",&t);
    while(t--){
        int k,a[K],b[K],p[K];bool f=0;
        scanf("%lld",&k);
        for(int i=1;i<=k;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=k;i++)
            scanf("%lld",&b[i]);
        for(int i=1;i<=k;i++)
            scanf("%lld",&p[i]);
        int c[K],d[K];
        for(int i=1;i<=k;i++){
            c[i]=1;d[i]=0;
            for(int j=1;j<=i;j++){
                c[i]=c[i]*a[j]%p[i];
                d[i]=(d[i]*a[j]+b[j])%p[i];
            }
            if(!c[i]&&d[i]){
                f=1;break;
            }
            if(!c[i]){d[i]=p[i]=1e9;continue;}
            int t;
            exgcd(c[i],p[i],c[i],t);
            d[i]=((-d[i])%p[i]+p[i])%p[i];
            d[i]=((d[i]*c[i])%p[i]+p[i])%p[i];
        }
        if(f){printf("No\n");continue;}
        pair<int,int>t[K];
        for(int i=1;i<=k;i++)
            t[i]=make_pair(p[i],d[i]);
        sort(t+1,t+k+1);
        for(int i=2;i<=k;i++)
            if(t[i].first==t[i-1].first
            &&t[i].second!=t[i-1].second){
                f=1;break;
            }
        printf(f?"No\n":"Yes\n");
    }
    return 0;
}