#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q;long long w;
long long a[N];
namespace SegTree{
    struct node{
        int l,r;
        long long sum;
        long long tag;
    }t[4*N];
    inline void pushup(int p){
        t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
    }
    inline void maketag(int p,long long k){
        t[p].sum+=(t[p].r-t[p].l+1)*k;
        t[p].tag+=k;
    }
    inline void pushdown(int p){
        if(t[p].tag){
            maketag(p<<1,t[p].tag);
            maketag(p<<1|1,t[p].tag);
            t[p].tag=0;
        }
    }
    void build(int p,int l,int r){
        t[p].l=l;t[p].r=r;t[p].tag=0;
        if(l==r){t[p].sum=a[l];return;}
        int mid=(l+r)/2;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        pushup(p);
    }
    void add(int p,int l,int r,long long k){
        if(t[p].l>=l&&t[p].r<=r){
            maketag(p,k);
            return;
        }
        pushdown(p);
        int mid=(t[p].l+t[p].r)/2;
        if(l<=mid)  add(p<<1,l,r,k);
        if(r>mid)   add(p<<1|1,l,r,k);
        pushup(p);
    }
    long long query(int p,long long k,long long mul){
        if(t[p].l==t[p].r)
            return t[p].l;
        pushdown(p);
        long long sum=t[p<<1].sum*mul;
        if(k<=sum)  return query(p<<1,k,mul);
        else                return query(p<<1|1,k-sum,mul);
    }
}
using namespace SegTree;
signed main(){
    scanf("%lld%lld%lld",&n,&q,&w);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    while(q--){
        int l,r;long long d;
        scanf("%lld%lld%lld",&l,&r,&d);
        add(1,l,r,d);
        long long cnt=log2((w-1)/t[1].sum+1);
        long long rem=(w-((1ll<<cnt)-1)*t[1].sum);
#ifdef DEBUG
        printf("cnt=%lld rem=%lld,sum=%lld\n",cnt,rem,t[1].sum);
#endif
        printf("%lld\n",cnt*n+query(1,rem,1ll<<cnt)-1);
    }
    return 0;
}