#include<bits/stdc++.h>
#define lowbit(x) (x)&(-(x))
using namespace std;
const int N=1e5+10,MOD=1e8-3;
int n;
struct pii{
    int a,b;
};
pii a[N],b[N];
int q[N];
int t[N],tot;
struct BIT{
    int c[N];
    BIT(){memset(c,0,sizeof(c));}
    void add(int i,int k){
        for(;i<=n;i+=lowbit(i))
            c[i]+=k;
    }
    int getsum(int i){
        int ans=0;
        for(;i;i-=lowbit(i))
            ans=(ans+c[i])%MOD;
        return ans;
    }
}bit;
int ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].a);
        a[i].b=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i].a);
        b[i].b=i;
    }
    sort(a+1,a+n+1,[](pii a,pii b){return a.a<b.a;});
    sort(b+1,b+n+1,[](pii a,pii b){return a.a<b.a;});
    for(int i=1;i<=n;i++)
        q[a[i].b]=b[i].b;
    reverse(q+1,q+n+1);
    for(int i=1;i<=n;i++){
        ans=(ans+bit.getsum(q[i]-1))%MOD;
        bit.add(q[i],1);
    }
    printf("%d",ans);
    return 0;
}