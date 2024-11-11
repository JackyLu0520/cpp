#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
struct node{
    int l,r;
    int sum;
    int ls,rs;
    node(){ls=0,rs=0;}
}t[N*16];
int root[N],tot=0;
void pushup(int p){
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
void build(int &p,int l,int r){
    if(!p)  p=++tot;
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].sum=a[l];return;}
    int mid=(l+r)/2;
    build(t[p].l,l,mid);
    build(t[p].r,mid+1,r);
    pushup(p);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
}