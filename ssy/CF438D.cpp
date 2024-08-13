#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
long long a[N];
struct node{
    int l,r;
    long long sum,Max;
}t[4*N];
void pushup(int p){
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
    t[p].Max=max(t[2*p].Max,t[2*p+1].Max);
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].sum=t[p].Max=a[l];return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);build(2*p+1,mid+1,r);
    pushup(p);
}
void mod(int p,int l,int r,long long x){
    if(t[p].l==t[p].r){
        t[p].sum=t[p].sum%x;
        t[p].Max=t[p].Max%x;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid&&t[2*p].Max>=x)  mod(2*p,l,r,x);
    if(r>mid&&t[2*p+1].Max>=x)   mod(2*p+1,l,r,x);
    pushup(p);
}
long long getsum(int p,int l,int r){
    if(l<=t[p].l&&r>=t[p].r)    return t[p].sum;
    int mid=(t[p].l+t[p].r)/2;
    long long ans=0;
    if(l<=mid)  ans+=getsum(2*p,l,r);
    if(r>mid)   ans+=getsum(2*p+1,l,r);
    return ans;
}
void change(int p,int k,int x){
    if(t[p].l==t[p].r){t[p].sum=t[p].Max=x;return;}
    int mid=(t[p].l+t[p].r)/2;
    if(k<=mid)  change(2*p,k,x);
    else        change(2*p+1,k,x);
    pushup(p);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int l,r;scanf("%d%d",&l,&r);
            printf("%lld\n",getsum(1,l,r));
        }else if(op==2){
            int l,r;long long x;scanf("%d%d%lld",&l,&r,&x);
            mod(1,l,r,x);
        }else{
            int k;long long x;scanf("%d%lld",&k,&x);
            change(1,k,x);
        }
    }
    return 0;
}