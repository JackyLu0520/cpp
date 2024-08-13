#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
struct node{
    int l,r;
    long long tag,lx,rx;
    bool a;
}t[4*N];
void pushup(int p){
    t[p].lx=t[2*p].lx;t[p].rx=t[2*p+1].rx;
    t[p].a=t[2*p].a&&t[2*p+1].a&&(t[2*p].rx<=t[2*p+1].lx);
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].lx=t[p].rx=a[l];t[p].a=1;t[p].lx=t[p].rx;return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);build(2*p+1,mid+1,r);
    pushup(p);
}
/*void preorder(int p){
    printf("[%d,%d]:{%lld...%lld},a=%d,tag=%lld\n",t[p].l,t[p].r,t[p].lx,t[p].rx,t[p].a,t[p].tag);
    if(t[p].l!=t[p].r){preorder(2*p);preorder(2*p+1);}
}*/
void pushdown(int p){
    if(t[p].tag){
        t[2*p].tag+=t[p].tag;
        t[2*p+1].tag+=t[p].tag;
        t[2*p].lx+=t[p].tag;t[2*p].rx+=t[p].tag;
        t[2*p+1].lx+=t[p].tag;t[2*p+1].rx+=t[p].tag;
        t[p].tag=0;
    }
}
void add(int p,int l,int r,long long k){
    if(l<=t[p].l&&r>=t[p].r){
        t[p].lx+=k;
        t[p].rx+=k;
        t[p].tag+=k;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  add(2*p,l,r,k);
    if(r>mid)   add(2*p+1,l,r,k);
    pushup(p);
}
bool isa(int p,int l,int r){
    if(l<=t[p].l&&r>=t[p].r)    return t[p].a;
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    bool ans=1;
    if(l<=mid)  ans=ans&&isa(2*p,l,r);
    if(r>mid)   ans=ans&&isa(2*p+1,l,r);
    if(l<=mid&&r>mid)   ans=ans&&(t[2*p].rx<=t[2*p+1].lx);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);//preorder(1);
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y,k;
            if(y>n) y=n;
            scanf("%d%d%d",&x,&y,&k);
            add(1,x,y,k);
        }else{
            int x,y;
            if(y>n) y=n;
            scanf("%d%d",&x,&y);
            printf(isa(1,x,y)?"Yes\n":"No\n");
        }
        //preorder(1);
    }
    return 0;
}