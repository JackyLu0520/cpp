#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
long long a[N];
struct node{
    int l,r;
    long long sum,Max;
    //bool tag=0;
}t[4*N];
void pushup(int p){
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
    t[p].Max=max(t[2*p].Max,t[2*p+1].Max);
    //t[p].tag=t[2*p].tag&&t[2*p+1].tag;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].sum=t[p].Max=a[l];return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);build(2*p+1,mid+1,r);
    pushup(p);
}
void rt(int p,int l,int r){
    if(t[p].l==t[p].r){
        t[p].sum=sqrt(t[p].sum);
        t[p].Max=sqrt(t[p].Max);
        //if(t[p].sum==1) t[p].tag=1;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid&&t[2*p].Max>1)  rt(2*p,l,r);
    if(r>mid&&t[2*p+1].Max>1)   rt(2*p+1,l,r);
    //if(l<=mid&&!t[2*p].tag)  rt(2*p,l,r);
    //if(r>mid&&!t[2*p+1].tag)   rt(2*p+1,l,r);
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
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(l>r) swap(l,r);
        if(op==0)
            rt(1,l,r);
        else
            printf("%lld\n",getsum(1,l,r));
    }
    return 0;
}