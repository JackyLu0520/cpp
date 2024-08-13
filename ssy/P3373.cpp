#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q;
long long m;
int a[N];
struct node{
    int l,r;
    long long sum,addtag,multag;
}t[4*N];
void pushup(int p){
    t[p].sum=(t[2*p].sum+t[2*p+1].sum)%m;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;t[p].addtag=0;t[p].multag=1;
    if(l==r){t[p].sum=a[l]%m;return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);build(2*p+1,mid+1,r);
    pushup(p);
}
void pushdown(int p){
    if(t[p].multag!=1){
        t[2*p].sum=(t[2*p].sum*t[p].multag)%m;
        t[2*p+1].sum=(t[2*p+1].sum*t[p].multag)%m;
        t[2*p].multag=(t[2*p].multag*t[p].multag)%m;
        t[2*p+1].multag=(t[2*p+1].multag*t[p].multag)%m;
        t[2*p].addtag=(t[2*p].addtag*t[p].multag)%m;
        t[2*p+1].addtag=(t[2*p+1].addtag*t[p].multag)%m;
        t[p].multag=1;
    }
    if(t[p].addtag){
        t[2*p].sum=(t[2*p].sum+t[p].addtag*(t[2*p].r-t[2*p].l+1)%m)%m;
        t[2*p+1].sum=(t[2*p+1].sum+t[p].addtag*(t[2*p+1].r-t[2*p+1].l+1)%m)%m;
        t[2*p].addtag=(t[2*p].addtag+t[p].addtag)%m;
        t[2*p+1].addtag=(t[2*p+1].addtag+t[p].addtag)%m;
        t[p].addtag=0;
    }
}
void add(int p,int l,int r,long long k){
    if(l<=t[p].l&&r>=t[p].r){
        t[p].sum=(t[p].sum+k*((t[p].r-t[p].l+1)%m)%m)%m;
        t[p].addtag=(t[p].addtag+k)%m;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  add(2*p,l,r,k);
    if(r>mid)   add(2*p+1,l,r,k);
    pushup(p);
}
void mul(int p,int l,int r,long long k){
    if(l<=t[p].l&&r>=t[p].r){
        t[p].sum=(t[p].sum*k)%m;
        t[p].multag=(t[p].multag*k)%m;
        if(t[p].addtag)    t[p].addtag=(t[p].addtag*k)%m;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  mul(2*p,l,r,k);
    if(r>mid)   mul(2*p+1,l,r,k);
    pushup(p);
}
long long getsum(int p,int l,int r){
    if(l<=t[p].l&&r>=t[p].r)    return t[p].sum;
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    long long ans=0;
    if(l<=mid)  ans=(ans+getsum(2*p,l,r))%m;
    if(r>mid)   ans=(ans+getsum(2*p+1,l,r))%m;
    return ans;
}
int main(){
    scanf("%d%d%lld",&n,&q,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            mul(1,x,y,k);
        }else if(op==2){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            add(1,x,y,k);
        }else{
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%lld\n",getsum(1,x,y));
        }
    }
    return 0;
}