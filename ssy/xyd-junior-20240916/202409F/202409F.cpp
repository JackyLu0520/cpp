#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,q,a[N],b[N],p,ans[N];
struct node{
    int l,r;
    int max;
}t[4*N];
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r)return;
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
}
void pushup(int p){
    t[p].max=max(t[2*p].max,t[2*p+1].max);
}
void add(int p,int i,int x){
    if(t[p].l==t[p].r){
        t[p].max+=x;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(i<=mid)  add(2*p,i,x);
    else        add(2*p+1,i,x);
    pushup(p);
}
int main(){
    freopen("202409F.in","r",stdin);
    freopen("202409F.out","w",stdout);
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    p=unique(b+1,b+n+1)-b-1;
    build(1,1,p);
    for(int i=1;i<=n;i++){
        if(i>k){
            int p1=lower_bound(b+1,b+p+1,a[i-k])-b;
            add(1,p1,-1);
        }
        int p2=lower_bound(b+1,b+p+1,a[i])-b;
        add(1,p2,1);
        ans[i]=t[1].max;
    }
    while(q--){
        int x;scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}