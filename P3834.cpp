#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int b[N],cnt;
struct node{
    int sum;
    int ls,rs;//lson,rson
    node(){ls=0,rs=0;}
}t[N*20];//0:NIL
int root[N],tot=0;
void pushup(int p){
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
void build(int &p,int l,int r){
    if(!p)  p=++tot;
    if(l==r){t[p].sum=0;return;}
    int mid=(l+r)/2;
    build(t[p].ls,l,mid);
    build(t[p].rs,mid+1,r);
    pushup(p);
}
void add(int &p,int q,int i,int k,int nowl,int nowr){//p:now q:pre
    if(!p)  p=++tot;
    if(nowl==nowr){
        t[p].sum=t[q].sum+k;
        return;
    }
    int mid=(nowl+nowr)/2;
    if(i<=mid)  t[p].rs=t[q].rs,add(t[p].ls,t[q].ls,i,k,nowl,mid);
    else        t[p].ls=t[q].ls,add(t[p].rs,t[q].rs,i,k,mid+1,nowr);
    pushup(p);
}
int query(int p,int q,int k,int nowl,int nowr){//p:r q:l-1
    if(nowl==nowr){
        return nowl;
    }
    int mid=(nowl+nowr)/2;
    int tmp=t[t[p].ls].sum-t[t[q].ls].sum;
    if(k<=tmp)  return query(t[p].ls,t[q].ls,k,nowl,mid);
    else        return query(t[p].rs,t[q].rs,k-tmp,mid+1,nowr);
}
/*void print(int p,int l,int r,int d,bool lr){
    if(!p)  return;
    for(int i=1;i<=d;i++)
        printf("\t");
    printf("%c:%d,[%d,%d],sum=%d\n",lr?'l':'r',p,l,r,t[p].sum);
    int mid=(l+r)/2;
    print(t[p].ls,l,mid,d+1,1);
    print(t[p].rs,mid+1,r,d+1,0);
}*/
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    cnt=unique(b+1,b+n+1)-b-1;
    build(root[0],1,cnt);
    for(int i=1;i<=n;i++){
        int p=lower_bound(b+1,b+cnt+1,a[i])-b;
        add(root[i],root[i-1],p,1,1,cnt);
    }
    while(m--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",b[query(root[r],root[l-1],k,1,cnt)]);
    }
    return 0;
}