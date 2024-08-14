#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,MAX=(1<<30)+1;
int n,q;
long long a[N];
struct node{
    int l,r;
    int lm,rm,mcnt;long long mul;
}t[4*N];
void pushup(int p){
    t[p].lm=t[2*p].mcnt?t[2*p].lm:t[2*p+1].lm;
    t[p].rm=t[2*p+1].mcnt?t[2*p+1].rm:t[2*p].rm;
    t[p].mcnt=t[2*p].mcnt+t[2*p+1].mcnt;
    t[p].mul=t[2*p].mul*t[2*p+1].mul;
    if(t[p].mul>MAX)    t[p].mul=MAX;
    if(t[p].mul< -MAX)  t[p].mul=-MAX;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        if(a[l]<0){
            t[p].lm=t[p].rm=l;
            t[p].mcnt=1;t[p].mul=a[l];
        }else{
            t[p].lm=MAX,t[p].rm=-1;
            t[p].mcnt=0;t[p].mul=a[l];
        }
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);build(2*p+1,mid+1,r);
    pushup(p);
}
/*void preorder(int p){
    printf("[%d,%d]:{%d...%d},len=%d,lmax=%d,rmax=%d,tmax=%d\n",t[p].l,t[p].r,t[p].lx,t[p].rx,t[p].len,t[p].lmax,t[p].rmax,t[p].tmax);
    if(t[p].l!=t[p].r){preorder(2*p);preorder(2*p+1);}
}*/
void change(int p,int k,long long x){
    if(t[p].l==t[p].r){
        if(x<0){
            t[p].lm=t[p].rm=t[p].l;
            t[p].mcnt=1;t[p].mul=x;
        }else{
            t[p].lm=MAX,t[p].rm=-1;
            t[p].mcnt=0;t[p].mul=x;
        }
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(k<=mid)  change(2*p,k,x);
    else        change(2*p+1,k,x);
    pushup(p);
}
int getlm(int p,int l,int r){
    if(l<=t[p].l&&r>=t[p].r)  return t[p].lm;
    int mid=(t[p].l+t[p].r)/2;
    int ans=MAX;
    if(l<=mid) ans=min(ans,getlm(2*p,l,r));
    if(r>mid)  ans=min(ans,getlm(2*p+1,l,r));
    return ans;
}
int getrm(int p,int l,int r){
    if(l<=t[p].l&&r>=t[p].r)  return t[p].rm;
    int mid=(t[p].l+t[p].r)/2;
    int ans=-1;
    if(l<=mid) ans=max(ans,getrm(2*p,l,r));
    if(r>mid)  ans=max(ans,getrm(2*p+1,l,r));
    return ans;
}
int getmcnt(int p,int l,int r){
    if(l<=t[p].l&&r>=t[p].r)  return t[p].mcnt;
    int mid=(t[p].l+t[p].r)/2;
    int ans=0;
    if(l<=mid) ans+=getmcnt(2*p,l,r);
    if(r>mid)  ans+=getmcnt(2*p+1,l,r);
    return ans;
}
long long getmul(int p,int l,int r){
    if(l>r) return 1;
    if(l<=t[p].l&&r>=t[p].r)  return t[p].mul;
    int mid=(t[p].l+t[p].r)/2;
    long long ans=1;
    if(l<=mid) ans*=getmul(2*p,l,r);
    if(r>mid)  ans*=getmul(2*p+1,l,r);
    if(ans>MAX) ans=MAX;
    if(ans< -MAX)ans=-MAX;
    return ans;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    //preorder(1);
    while(q--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
            change(1,x,y);
        else{
            long long ans;
            if((getmcnt(1,x,y)&1)==0)
                ans=getmul(1,x,y);
            else
                ans=max(getmul(1,x,getrm(1,x,y)-1),getmul(1,getlm(1,x,y)+1,y));
            if(ans>=MAX)    printf("Too large\n");
            else            printf("%lld\n",ans);    
        }
    }
    return 0;
}