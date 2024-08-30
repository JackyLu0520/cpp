#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=62;
int n,q;
long long a[N];
bool zero;
int main(){
    int t;scanf("%d",&t);
    for(int cnt=1;cnt<=t;cnt++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        int r=1,c=M;
        for(;r<=n&&c>=0;c--){
            int cur;for(cur=r;cur<=n&&!((a[cur]>>c)&1);cur++);
            if(cur>n) continue;
            swap(a[r],a[cur]);
            for(int j=1;j<=n;j++)
                if(r!=j&&((a[j]>>c)&1))
                    a[j]^=a[r];
            r++;
        }
        r--;
        if(r!=n)    zero=1;
        else        zero=0;
        n=r;
        scanf("%d",&q);
        printf("Case #%d:\n",cnt);
        while(q--){
            long long k,ans=0;scanf("%lld",&k);
            if(zero)    k--;
            if(!k){printf("0\n");continue;}
            for(int i=n;i>0;i--){
                if(k&1) ans^=a[i];
                k>>=1;
            }
            if(k)   printf("-1\n");
            else    printf("%lld\n",ans);
        }
    }
    return 0;
}