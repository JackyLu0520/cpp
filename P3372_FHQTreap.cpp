#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int ls,rs;
    int val,pri;
    int size,tag,sum;
}t[N];int tot=0;
struct FHQTreap{
    int root=0;
    int newnode(int x){
        int p=++tot;
        t[p].ls=t[p].rs=0;
        t[p].val=x;t[p].pri=rand();
        t[p].size=1;t[p].tag=0;t[p].sum=x;
        return p;
    }
    void pushup(int p){
        t[p].size=t[t[p].ls].size+t[t[p].rs].size;
        t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum+t[p].val;
    }
    void maketag(int p,int add){
        t[p].val+=add;
        t[p].tag+=add;
        t[p].sum+=t[p].size*add;
    }
    void pushdown(int p){
        if(t[p].tag){
            maketag(t[p].ls,t[p].tag);
            maketag(t[p].rs,t[p].tag);
            t[p].tag=0;
        }
    }
    void split(int p,int rank,int &L,int &R){//by rank
        if(!p){L=R=0;return;}
        pushdown(p);
        if(t[t[p].ls].size>=rank){
            split(t[p].ls,rank,L,t[p].ls);
            R=p;
        }else{
            split(t[p].rs,rank-t[t[p].ls].size-1,t[p].rs,R);
            L=p;
        }
        pushup(p);
    }
    int merge(int L,int R){
        if(!L||!R)  return L+R;
        if(t[L].pri>t[R].pri){
            pushdown(L);
            t[L].rs=merge(t[L].rs,R);
            pushup(L);
            return L;
        }else{
            pushdown(R);
            t[R].ls=merge(L,t[R].ls);
            pushup(R);
            return R;
        }
    }
    void add(int l,int r,int k){
        int L,M,R;
        split(root,r,L,R);
        split(L,l-1,L,M);
        maketag(M,k);
        root=merge(merge(L,M),R);
    }
    int query(int l,int r){
        int L,M,R;
        split(root,r,L,R);
        split(L,l-1,L,M);
        int ans=t[M].sum;
        root=merge(merge(L,M),R);
        return ans;
    }
    void push_back(int x){
        root=merge(root,newnode(x));
    }
}tree;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        tree.push_back(x);
    }
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int x,y,k;scanf("%d%d%d",&x,&y,&k);
            tree.add(x,y,k);
        }else{
            int x,y;scanf("%d%d",&x,&y);
            printf("%d\n",tree.query(x,y));
        }
    }
    return 0;
}