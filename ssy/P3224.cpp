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
    if(t[p].key<key){
        R=p;
        split(p,key,L,t[p].ls);
    }else{
        L=p;
        split(p,key,t[p].rs,R);
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
    else
        return query(t[p].rs,rank-t[t[p].ls].size-1);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d",&p);
        root[i]=newnode(p,i);
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        root[u]=root[v]=merge(root[u],root[v]);
    }
    scanf("%d",&q);
    while(q--){
        char op;
        int x,y;
        scanf(" %c%d%d",&op,&x,&y);
        if(op=='Q')
            printf("%d\n",query(root[x],y));
        else
            root[x]=root[y]=merge(root[x],root[y]);
    }
    return 0;
}