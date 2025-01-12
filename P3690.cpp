#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
struct node{
    int ch[2],fa;
    int sum,val;//xorsum
    bool tag;//reverse
}t[N];
inline void pushup(int p){
    t[p].sum=t[t[p].ch[0]].sum^t[t[p].ch[1]].sum^t[p].val;
}
inline void reverse(int p){
    if(!p)  return;
    t[p].tag^=1;
    swap(t[p].ch[0],t[p].ch[1]);
}
inline void pushdown(int p){
    if(t[p].tag){
        reverse(t[p].ch[0]);
        reverse(t[p].ch[1]);
        t[p].tag=0;
    }
}
inline bool isroot(int p){
    return t[t[p].fa].ch[0]!=p&&t[t[p].fa].ch[1]!=p;
}
inline bool get(int p){
    return t[p].ch[1]==p;
}
inline void rotate(int p){
    int f=t[p].fa,g=t[f].fa;
    int d1=get(f),d2=get(p);
    int s=t[p].ch[!d2];
    t[g].ch[d1]=p;t[p].fa=g;
    t[p].ch[!d2]=f;t[f].fa=p;
    t[f].ch[d2]=s;t[s].fa=f;
    pushup(f);pushup(p);
}
void push(int p){
    if(!isroot(p))  push(t[p].fa);
    pushdown(p);
}
inline void splay(int p){
    push(p);
    while(!isroot(p)){
        int f=t[p].fa;
        if(!isroot(f))
            get(p)==get(f)?rotate(f):rotate(p);
        rotate(p);
    }
}
inline void access(int p){
    for(int ch=0;p;ch=p,p=t[p].fa){
        splay(p);
        t[p].ch[1]=ch;
        pushup(p);
    }
}
inline void makeroot(int p){
    access(p);
    splay(p);
    reverse(p);
}
inline void split(int p,int q){
    makeroot(p);
    access(q);
    splay(q);
}
inline int findroot(int p){
    access(p);
    splay(p);
    while(t[p].ch[0]){
        pushdown(p);
        p=t[p].ch[0];
    }
    return p;
}
inline void link(int p,int q){
    if(findroot(p)==findroot(q))
        return;
    makeroot(p);
    t[p].fa=q;
}
inline void cut(int p,int q){
    split(p,q);
    if(t[q].ch[0]!=p||t[p].ch[1])
        return;
    t[p].fa=t[q].ch[0]=0;
    pushup(q);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i].val),pushup(i);
    while(m--){
        int op,u,v;
        scanf("%d%d%d",&op,&u,&v);
        switch(op){
            case 0:split(u,v);printf("%d\n",t[v].sum);break;
            case 1:link(u,v);break;
            case 2:cut(u,v);break;
            case 3:splay(u);t[u].val=v;pushup(u);break;
        }
    }
    return 0;
}