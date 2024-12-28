#include<bits/stdc++.h>
#define DEBUG
using namespace std;
const int N=3e5+10,M=3e5+10,L=22;
int n,m;
struct node{
    int ch[2];
    int l,r;
}t[(N+M)*(L+1)];int tot=1;
int xorall=0,root=1;
inline void pushup(int p){
    t[p].l=min(t[t[p].ch[0]].l,t[t[p].ch[1]].r);
    t[p].r=max(t[t[p].ch[0]].r,t[t[p].ch[1]].r);
}
void insert(int &p,int x,int pos,int id){
    if(!p){
        p=++tot;
        t[p].ch[0]=t[p].ch[1]=0;
        t[p].l=2147483647;
        t[p].r=0;
    }
    if(pos==-1){
        t[p].ch[0]=t[p].ch[1]=0;
        t[p].l=min(t[p].l,id);
        t[p].r=max(t[p].r,id);
        return;
    }
    insert(t[p].ch[(x>>pos)&1],x,pos-1,id);
    pushup(p);
}
int query(int p,int x,int pos,int l,int r,int val){
    if(pos==-1) return val^x;
    int c=(x>>pos)&1;
    if(!t[p].ch[c]||t[t[p].ch[c]].l>r||t[t[p].ch[c]].r<l)
        return query(t[p].ch[c^1],x,pos-1,l,r,val|((c^1)<<pos));
    else
        return query(t[p].ch[c],x,pos-1,l,r,val|(c<<pos));
}
#ifdef DEBUG
void print(int p,int lr,int depth){
    if(!p)  return;
    for(int i=1;i<=depth;i++)
        printf(" ");
    printf("%d:l=%d,r=%d\n",lr,t[p].l,t[p].r);
    print(t[p].ch[0],0,depth+1);
    print(t[p].ch[1],1,depth+1);
}
#endif
int main(){
    scanf("%d%d",&n,&m);
    t[0].ch[0]=t[0].ch[1]=0;
    t[0].l=2147483647;t[0].r=0;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        xorall^=x;
        insert(root,xorall,L,i);
    }
    while(m--){
        char op;
        scanf(" %c",&op);
        if(op=='A'){
            int x;
            scanf("%d",&x);
            xorall^=x;
            insert(root,xorall,L,++n);
        }else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",query(root,x^xorall,L,l-1,r-1,0));
        }
#ifdef DEBUG
        print(root,0,0);
#endif
    }
    return 0;
}