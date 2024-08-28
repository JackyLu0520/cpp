#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,x,a[N];
int f[N],l[N],r[N],len,ans=0;
int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(f,~0x7f,sizeof f);len=0;
    for(int i=1;i<=n;i++){
        if(a[i]>f[len]) f[++len]=a[i],l[i]=len;
        else{auto j=lower_bound(f+1,f+len+1,a[i]);*j=a[i];l[i]=j-f;}
    }
    memset(f,~0x7f,sizeof f);len=0;
    for(int i=n;i>=1;i--){
        r[i]=lower_bound(f+1,f+len+1,-a[i]+x)-f;
        if(-a[i]>f[len]) f[++len]=-a[i];
        else    *lower_bound(f+1,f+len+1,-a[i])=-a[i];
    }
    /*for(int i=1;i<=n;i++)
        printf("%d ",l[i]);
    printf("\n");
    for(int i=1;i<=n;i++)
        printf("%d ",r[i]);
    printf("\n");*/
    for(int i=1;i<=n;i++)
        ans=max(ans,l[i]+r[i]-1);
    printf("%d",ans);
    return 0;
}