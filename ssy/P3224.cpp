#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,q;
struct node{
    int ls,rs;
    int key,val;
    int pri;
    int size;
}t[N];int tot=0;
int root[N];
inline int newnode(int key,int val){
    int p=++tot;
    t[p].ls=t[p].rs=0;
    t[p].key=key;t[p].val=val;
    t[p].pri=rand();
    t[p].size=1;
    return p;
}
inline void pushup(int p){
    t[p].size=t[t[p].ls].size+t[t[p].rs].size+1;
}
void split(int p,int key,int &L,int &R){
    if(!p){L=R=0;return;}
    if(t[p].key>key){
        R=p;
        split(t[p].ls,key,L,t[p].ls);
    }else{
        L=p;
        split(t[p].rs,key,t[p].rs,R);
    }
    pushup(p);
}
int merge(int p,int q){
    if(!p||!q)  return p+q;
    if(p==q)    return p;
    if(t[p].pri<t[q].pri)
        swap(p,q);
    int l,r;
    split(q,t[p].key,l,r);
    t[p].ls=merge(t[p].ls,l);
    t[p].rs=merge(t[p].rs,r);
    pushup(p);
    return p;
}
int query(int p,int rank){
    if(t[t[p].ls].size>=rank)
        return query(t[p].ls,rank);
    else if(t[t[p].ls].size+1==rank)
        return t[p].val;
    else if(t[p].size>=rank)
        return query(t[p].rs,rank-t[t[p].ls].size-1);
    else
        return -1;
}
#ifdef DEBUG
void inorder(int p){
    if(!p)  return;
    inorder(t[p].ls);
    printf("%d:%d ",t[p].key,t[p].val);
    inorder(t[p].rs);
}
#endif
struct dsu{
    int fa[N];
    dsu(int n){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
int main(){
    scanf("%d%d",&n,&m);
    dsu d(n);
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d",&p);
        root[i]=newnode(p,i);
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        int uu=d.query(u),vv=d.query(v);
        d.merge(uu,vv);
        root[d.query(uu)]=merge(root[uu],root[vv]);
    }
#ifdef DEBUG
    for(int i=1;i<=n;i++){
        printf("%d:",i);
        inorder(root[d.query(i)]);
        printf("\n");
    }
#endif
    scanf("%d",&q);
    while(q--){
        char op;
        int x,y;
        scanf(" %c%d%d",&op,&x,&y);
        if(op=='Q')
            printf("%d\n",query(root[d.query(x)],y));
        else{
            int xx=d.query(x),yy=d.query(y);
            d.merge(xx,yy);
            root[d.query(xx)]=merge(root[xx],root[yy]);
#ifdef DEBUG
            for(int i=1;i<=n;i++){
                printf("%d:",i);
                inorder(root[d.query(i)]);
                printf("\n");
            }
#endif
        }
    }
    return 0;
}