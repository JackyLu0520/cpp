#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,A=2e5+10,L=22,M=2e5+10;
int n,m;
int a[N];
struct node{
    int id;
    int ls,rs;
}t[2*A+L*N];int tot=0;
int root[N];
inline void pushup(int p){
    t[p].id=min(t[t[p].ls].id,t[t[p].rs].id);
}
void build(int &p,int l,int r){
    if(!p)  p=++tot;
    if(l==r){t[p].id=0;return;}
    int mid=(l+r)/2;
    build(t[p].ls,l,mid);
    build(t[p].rs,mid+1,r);
    pushup(p);
}
void modify(int &p,int q,int i,int k,int l,int r){
    if(!p)  p=++tot;
    if(l==r){
        t[p].id=k;
        return;
    }
    int mid=(l+r)/2;
    if(i<=mid)  t[p].rs=t[q].rs,modify(t[p].ls,t[q].ls,i,k,l,mid);
    else        t[p].ls=t[q].ls,modify(t[p].rs,t[q].rs,i,k,mid+1,r);
    pushup(p);
}
int query(int p,int k,int l,int r){
    if(l==r)    return l;
    int mid=(l+r)/2;
    if(t[t[p].ls].id<k) return query(t[p].ls,k,l,mid);
    else                return query(t[p].rs,k,mid+1,r);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(root[0],0,A);
    for(int i=1;i<=n;i++)
        modify(root[i],root[i-1],a[i],i,0,A);
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(root[r],l,0,A));
    }
    return 0;
}