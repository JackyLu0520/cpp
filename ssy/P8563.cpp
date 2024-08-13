#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,MAX=1<<30+1;
int n,m;
long long a[N]={0};
struct node{
    int l,r;
    long long lm,rm,mcnt,mul;
}t[4*N];
void pushup(int p){
    t[p].lm=t[2*p].mcnt?t[2*p].lm:t[2*p+1].lm;
    t[p].rm=t[2*p+1].mcnt?t[2*p+1].rm:t[2*p].rm;
    t[p].mcnt=t[2*p].mcnt+t[2*p+1].mcnt;
    t[p].mul=t[2*p].mul*t[2*p+1].mul;
    if(t[p].mul>MAX)    t[p].mul=MAX;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        if(a[l]<0){
            t[p].lm=t[p].rm=l;
            t[p].mcnt=1;t[p].mul=1;
        }else{
            t[p].lm=t[p].rm=-1;
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
void change(int p,int k,int x){
    if(t[p].l==t[p].r){
        if(x<0){
            t[p].lm=t[p].rm=t[p].l;
            t[p].mcnt=1;t[p].mul=x;
        }else{
            t[p].lm=t[p].rm=-1;
            t[p].mcnt=0;t[p].mul=x;
        }
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(k<=mid)  change(2*p,k,x);
    else        change(2*p+1,k,x);
    pushup(p);
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    //preorder(1);
    while(m--){
    }
    return 0;
}