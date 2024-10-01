#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,q;
int a[N];
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i]=a[i]&1;
    while(q--){
        int l,r;scanf("%d%d",&l,&r);
        long long ans=(r-l+2)*(r-l+1)/2;
        for(int i=l;i<=r;){
            int k=i;
            while(k<r&&a[k]==a[k+1]) k++;
            ans-=(k-i+2)*(k-i+1)/2;
            //printf("%d ",k);
            i=k+1;
        }
        //printf("\n");
        printf("%lld\n",ans);
    }
    return 0;
}