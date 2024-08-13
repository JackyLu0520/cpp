#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
bool a[N]={0};
struct node{
    int l,r,len;
    int lmax,rmax,tmax;bool lx,rx;
}t[4*N];
void pushup(int p){
    t[p].lx=t[2*p].lx;t[p].rx=t[2*p+1].rx;
    t[p].lmax=(t[2*p].rx!=t[2*p+1].lx&&t[2*p].tmax==t[2*p].len)?t[2*p].len+t[2*p+1].lmax:t[2*p].lmax;
    t[p].rmax=(t[2*p].rx!=t[2*p+1].lx&&t[2*p+1].tmax==t[2*p+1].len)?t[2*p+1].len+t[2*p].rmax:t[2*p+1].rmax;
    t[p].tmax=(t[2*p].rx==t[2*p+1].lx)?max(t[2*p].tmax,t[2*p+1].tmax):max(max(t[2*p].tmax,t[2*p+1].tmax),t[2*p].rmax+t[2*p+1].lmax);
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;t[p].len=r-l+1;
    if(l==r){
        t[p].tmax=t[p].lmax=t[p].rmax=1;
        t[p].lx=t[p].rx=a[l];
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
void change(int p,int k){
    if(t[p].l==t[p].r){t[p].lx=t[p].rx=!t[p].lx;return;}
    int mid=(t[p].l+t[p].r)/2;
    if(k<=mid)  change(2*p,k);
    else        change(2*p+1,k);
    pushup(p);
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    //preorder(1);
    while(m--){
        int x;
        scanf("%d",&x);
        change(1,x);
        printf("%d\n",t[1].tmax);
        //preorder(1);
    }
    return 0;
}