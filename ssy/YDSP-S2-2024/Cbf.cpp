#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)+10;
int n,q,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    while(q--){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        int ans=0;
        for(int i=l;i<=r;i++){
            ans=max(ans,a[i]|x);
            printf("%d,%d ",i,a[i]|x);
        }
        printf("\n");
        printf("%d\n",ans);
    }
    return 0;
}