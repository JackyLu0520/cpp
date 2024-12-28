#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e6+10;
int n,m;
int a[N];
struct node{
    int ls,rs;
    int val;
}t[(N<<1)+(M<<5)];int tot=0;
int root[M];
void build(int &p,int l,int r){
    if(!p)  p=++tot;
    if(l==r){t[p].val=a[l];return;}
    int mid=(l+r)/2;
    build(t[p].ls,l,mid);
    build(t[p].rs,mid+1,r);
}
void modify(int &p,int q,int i,int k,int pl,int pr){
    if(!p)  p=++tot;
    if(pl==pr){
        t[p].val=k;
        return;
    }
    int mid=(pl+pr)/2;
    if(i<=mid)  t[p].rs=t[q].rs,modify(t[p].ls,t[q].ls,i,k,pl,mid);
    else        t[p].ls=t[q].ls,modify(t[p].rs,t[q].rs,i,k,mid+1,pr);
}
inline void copy(int &p,int q){
    if(!p)  p=++tot;
    t[p].ls=t[q].ls;t[p].rs=t[q].rs;
}
int query(int p,int i,int pl,int pr){
    if(pl==pr)
        return t[p].val;
    int mid=(pl+pr)/2;
    if(i<=mid)  return query(t[p].ls,i,pl,mid);
    else        return query(t[p].rs,i,mid+1,pr);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(root[0],1,n);
    for(int i=1;i<=m;i++){
        int pre,op,pos;
        scanf("%d%d%d",&pre,&op,&pos);
        if(op==1){
            int k;
            scanf("%d",&k);
            modify(root[i],root[pre],pos,k,1,n);
        }else{
            copy(root[i],root[pre]);
            printf("%d\n",query(root[i],pos,1,n));
        }
    }
    return 0;
}