#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,s,a[N],sum=0,ans=0;
int main(){
    freopen("202409D.in","r",stdin);
    freopen("202409D.out","w",stdout);
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=0;
    while(r<n){
        r++;sum+=a[r];
        while(sum>s)    sum-=a[l],l++;
        ans+=r-l+1;
        //fprintf(stderr,"%d %d %d\n",l,r,sum);
    }
    printf("%d",ans);
    return 0;
}