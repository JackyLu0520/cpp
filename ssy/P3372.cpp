#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[N];
struct node{
    int l,r;
    long long sum,tag;
}t[4*N];
void pushup(int p){
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].sum=a[l];return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);build(2*p+1,mid+1,r);
    pushup(p);
}
void pushdown(int p){
    if(t[p].tag){
        t[2*p].sum+=t[p].tag*(t[2*p].r-t[2*p].l+1);
        t[2*p+1].sum+=t[p].tag*(t[2*p+1].r-t[2*p+1].l+1);
        t[2*p].tag+=t[p].tag;
        t[2*p+1].tag+=t[p].tag;
        t[p].tag=0;
    }
}
void add(int p,int l,int r,long long k){
    if(l<=t[p].l&&r>=t[p].r){
        t[p].sum+=k*(t[p].r-t[p].l+1);
        t[p].tag+=k;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  add(2*p,l,r,k);
    if(r>mid)   add(2*p+1,l,r,k);
    pushup(p);
}
long long getsum(int p,int l,int r){
    if(l<=t[p].l&&r>=t[p].r)    return t[p].sum;
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    long long ans=0;
    if(l<=mid)  ans+=getsum(2*p,l,r);
    if(r>mid)   ans+=getsum(2*p+1,l,r);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
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