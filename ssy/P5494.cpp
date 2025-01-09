#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=2e5+10;
int n,m;
struct node{
    node *ls,*rs;
    int val,cnt;
    int pri;
    int size;
};
node *root[M];int tot=1;
node *null;
inline node *newnode(int val,int cnt){
    node *p=new node;
    p->ls=p->rs=null;
    p->val=val;p->cnt=cnt;
    p->pri=rand();
    p->size=cnt;
    return p;
}
inline void pushup(node *p){
    p->size=p->ls->size+p->rs->size+p->cnt;
}
void split(node *p,int val,node *&l,node *&r){
    if(p==null){l=r=null;return;}
    if(p->val>val){
        r=p;
        split(p->ls,val,l,p->ls);
    }else{
        l=p;
        split(p->rs,val,p->rs,r);
    }
    pushup(p);
}
node *merge(node *l,node *r){
    if(l==null)  return r;
    if(r==null)  return l;
    if(l->pri>r->pri){
        l->rs=merge(l->rs,r);
        pushup(l);
        return l;
    }else{
        r->ls=merge(l,r->ls);
        pushup(r);
        return r;
    }
}
node *Merge(node *p,node *q){
    if(p==null)  return q;
    if(q==null)  return p;
    if(p->pri<q->pri)
        swap(p,q);
    node *l,*mid,*r;
    split(q,p->val,l,r);
    split(l,p->val-1,l,mid);
    if(mid!=null){
        p->cnt+=mid->cnt;
        delete mid;
        mid=null;
    }
    p->ls=Merge(p->ls,l);
    p->rs=Merge(p->rs,r);
    pushup(p);
    return p;
}
inline void add(node *&p,int val,int cnt){
    if(cnt==0)  return;
    node *l,*mid,*r;
    split(p,val,l,r);
    split(l,val-1,l,mid);
    if(mid==null)   mid=newnode(val,cnt);
    else            mid->cnt+=cnt;
    pushup(mid);
    p=merge(merge(l,mid),r);
}
inline int querysize(node *&p,int x,int y){
    node *l,*mid,*r;
    split(p,y,l,r);
    split(l,x-1,l,mid);
    int ans=mid->size;
    p=merge(merge(l,mid),r);
    return ans;
}
int queryval(node *p,int rank){
    if(p->ls->size>=rank)   return queryval(p->ls,rank);
    else if(p->ls->size+p->cnt>=rank)    return p->val;
    else if(p->size>=rank)  return queryval(p->rs,rank-p->ls->size-p->cnt);
    else    return -1;
}
#ifdef DEBUG
void inorder(node *p){
    if(p==null) return;
    inorder(p->ls);
    printf("%lld:%lld ",p->val,p->cnt);
    inorder(p->rs);
}
#endif
signed main(){

    null=new node;
    null->ls=null->rs=null;
    null->val=null->cnt=0;
    null->pri=-1;null->size=0;

    scanf("%lld%lld",&n,&m);
    root[1]=null;
    for(int i=1;i<=n;i++){
        int cnt;
        scanf("%lld",&cnt);
        add(root[1],i,cnt);
    }
    while(m--){
        int op;
        scanf("%lld",&op);
        int p,x,y,k;
        switch(op){
            case 0:
                scanf("%lld%lld%lld",&p,&x,&y);
                node *l,*mid,*r;
                split(root[p],y,l,r);
                split(l,x-1,l,mid);
                root[p]=merge(l,r);
                root[++tot]=mid;
            break;
            case 1:
                scanf("%lld%lld",&p,&k);
                root[p]=Merge(root[p],root[k]);
            break;
            case 2:
                scanf("%lld%lld%lld",&p,&k,&x);
                add(root[p],x,k);
            break;
            case 3:
                scanf("%lld%lld%lld",&p,&x,&y);
                printf("%lld\n",querysize(root[p],x,y));
            break;
            case 4:
                scanf("%lld%lld",&p,&k);
                printf("%lld\n",queryval(root[p],k));
            break;
#ifdef DEBUG
            case 5:
                scanf("%lld",&p);
                printf("%lld|",p);
                inorder(root[p]);
                printf("\n");
            break;
#endif
            default:
            break;
        }
    }
    return 0;
}