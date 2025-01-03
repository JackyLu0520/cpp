#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5+10,L=22;
int n,m;
long long a[N];
struct node{
    long long sum;
    long long tag;
    int ls,rs;
}t[2*N+L*M];int tot=0;
int root[M];
inline void pushup(int p,int l,int r){
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum+(r-l+1)*t[p].tag;
}
void build(int &p,int l,int r){
    p=++tot;t[p].ls=t[p].rs=0;t[p].tag=0;
    if(l==r){t[p].sum=a[l];return;}
    int mid=(l+r)/2;
    build(t[p].ls,l,mid);
    build(t[p].rs,mid+1,r);
    pushup(p,l,r);
}
void add(int &p,int q,int l,int r,long long k,int pl,int pr){
    p=++tot,t[p]=t[q];
    if(pl==l&&pr==r){
        t[p].tag+=k;
        pushup(p,pl,pr);
        return;
    }
    int mid=(pl+pr)/2;
    if(r<=mid)      add(t[p].ls,t[q].ls,l,r,k,pl,mid);
    else if(l>mid)  add(t[p].rs,t[q].rs,l,r,k,mid+1,pr);
    else            add(t[p].ls,t[q].ls,l,mid,k,pl,mid),add(t[p].rs,t[q].rs,mid+1,r,k,mid+1,pr);
    pushup(p,pl,pr);
}
long long query(int p,int l,int r,int pl,int pr){
    if(!p)  return 0;
    if(pl==l&&pr==r)
        return t[p].sum;
    int mid=(pl+pr)/2;
    long long ans=t[p].tag*(r-l+1);
    if(r<=mid)      ans+=query(t[p].ls,l,r,pl,mid);
    else if(l>mid)  ans+=query(t[p].rs,l,r,mid+1,pr);
    else            ans+=query(t[p].ls,l,mid,pl,mid)+query(t[p].rs,mid+1,r,mid+1,pr);
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        tot=0;
        memset(root,0,sizeof(root));
        build(root[0],1,n);
        int cur=0;
        while(m--){
            char op;
            scanf(" %c",&op);
            if(op=='C'){
                int l,r;long long d;
                scanf("%d%d%lld",&l,&r,&d);
                cur++;
                add(root[cur],root[cur-1],l,r,d,1,n);
            }else if(op=='Q'){
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(root[cur],l,r,1,n));
            }else if(op=='H'){
                int l,r,t;
                scanf("%d%d%d",&l,&r,&t);
                printf("%lld\n",query(root[t],l,r,1,n));
            }else{
                int t;
                scanf("%d",&t);
                tot=root[t+1]-1;
                cur=t;
            }
        }
    }
    return 0;
}