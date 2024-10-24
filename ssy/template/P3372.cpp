#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
long long a[N];
struct node{
    int l,r;
    long long tag;
    long long sum;
}t[4*N];
void pushup(int p){
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].sum=a[l];t[p].tag=0;return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    pushup(p);
}
void pushdown(int p){
    if(t[p].tag){
        t[2*p].tag+=t[p].tag;
        t[2*p+1].tag+=t[p].tag;
        t[2*p].sum+=(t[2*p].r-t[2*p].l+1)*t[p].tag;
        t[2*p+1].sum+=(t[2*p+1].r-t[2*p+1].l+1)*t[p].tag;
        t[p].tag=0;
    }
}
void add(int p,int l,int r,long long k){
    if(t[p].l>=l&&t[p].r<=r){
        t[p].tag+=k;
        t[p].sum+=(t[p].r-t[p].l+1)*k;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  add(2*p,l,r,k);
    if(r>=mid+1)add(2*p+1,l,r,k);
    pushup(p);
}
long long query(int p,int l,int r){
    if(t[p].l>=l&&t[p].r<=r){
        return t[p].sum;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    long long ans=0;
    if(l<=mid)  ans+=query(2*p,l,r);
    if(r>=mid+1)ans+=query(2*p+1,l,r);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int l,r;
            long long k;
            scanf("%d%d%lld",&l,&r,&k);
            add(1,l,r,k);
        }else{
            int l,r;scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,l,r));
        }
    }
    return 0;
}