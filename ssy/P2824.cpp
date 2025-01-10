#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5+10;
int n,m,q;
int a[N];
struct op{
    int op,l,r;
}ops[M];
struct node{
    int l,r;
    int sum;
    int tag;
}t[4*N];
inline void pushup(int p){
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}
inline void maketag(int p,int k){
    t[p].tag=k;
    t[p].sum=k*(t[p].r-t[p].l+1);
}
inline void pushdown(int p){
    if(t[p].tag!=-1){
        maketag(p<<1,t[p].tag);
        maketag(p<<1|1,t[p].tag);
        t[p].tag=-1;
    }
}
void build(int p,int l,int r,int k){
    t[p].l=l;t[p].r=r;t[p].tag=-1;
    if(l==r){t[p].sum=(a[l]>=k);return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid,k);
    build(p<<1|1,mid+1,r,k);
    pushup(p);
}
void overwrite(int p,int l,int r,int k){
    if(l>r) return;
    if(t[p].l>=l&&t[p].r<=r){
        maketag(p,k);
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid)  overwrite(p<<1,l,r,k);
    if(r>mid)   overwrite(p<<1|1,l,r,k);
    pushup(p);
}
int query(int p,int l,int r){
    if(t[p].l>=l&&t[p].r<=r)
        return t[p].sum;
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    int ans=0;
    if(l<=mid)  ans+=query(p<<1,l,r);
    if(r>mid)   ans+=query(p<<1|1,l,r);
    return ans;
}
bool check(int x){
    build(1,1,n,x);
    for(int i=1;i<=m;i++){
        int op=ops[i].op,l=ops[i].l,r=ops[i].r;
        int cnt=query(1,l,r);
        if(cnt==0||cnt==r-l+1)
            continue;
        if(op){
            overwrite(1,l,l+cnt-1,1);
            overwrite(1,l+cnt,r,0);
        }else{
            overwrite(1,l,r-cnt+1,0);
            overwrite(1,r-cnt+1,r,1);
        }
    }
    return query(1,q,q);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&ops[i].op,&ops[i].l,&ops[i].r);
    scanf("%d",&q);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid))  l=mid;
        else            r=mid-1;
    }
    printf("%d",l);
    return 0;
}