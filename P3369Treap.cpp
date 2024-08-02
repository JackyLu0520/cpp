#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=0x7fffffff;
typedef int ptr;
struct node{
    int val,cnt,pri;
    ptr l,r;
    int size;
};
template<class T>
struct mem{
    T a[N];
    int tot=0;
    queue<int> q;
    ptr alloc(){
        if(q.empty())   return ++tot;
        else            {int t=q.front();q.pop();return t;}
    }
    void del(ptr &p){
        q.push(p);
        p=0;
    }
    T &operator [] (int i){
        return a[i];
    }
};
struct Treap{
    mem<node> m;
    ptr root,infp,minfp;
    ptr newnode(int x){
        ptr p=m.alloc();
        m[p].val=x;
        m[p].size=m[p].cnt=1;
        m[p].pri=rand();
        return p;
    }
    void update(ptr p){
        m[p].size=m[m[p].l].size+m[m[p].r].size+m[p].cnt;
    }
    void build(){
        minfp=root=newnode(-INF);infp=m[root].r=newnode(INF);
        update(root);
    }
    void zig(ptr &p){
        ptr t=m[p].l;
        m[p].l=m[t].r;
        m[t].r=p;p=t;
        update(m[p].r);update(p);
    }
    void zag(ptr &p){
        ptr t=m[p].r;
        m[p].r=m[t].l;
        m[t].l=p;p=t;
        update(m[p].l);update(p);
    }
    void insert(int x,ptr &p){
        if(p==0){p=newnode(x);return;}
        if(m[p].val==x){m[p].cnt++;update(p);return;}
        if(x<m[p].val){
            insert(x,m[p].l);
            if(m[p].pri<m[m[p].l].pri)    zig(p);
        }
        else{
            insert(x,m[p].r);
            if(m[p].pri<m[m[p].r].pri)    zag(p);
        }
        update(p);
    }
    void remove(int x,ptr &p){
        if(p==0)    return;
        if(x==m[p].val){
            if(m[p].cnt>1){
                m[p].cnt--;update(p);
                return;
            }
            if(m[p].l||m[p].r){
                if(m[p].l||m[m[p].l].pri>m[m[p].r].pri)
                    zig(p),remove(x,m[p].r);
                else
                    zag(p),remove(x,m[p].l);
                update(p);
            }else   m.del(p);
            return;
        }
        if(x<m[p].val)  remove(x,m[p].l);
        else            remove(x,m[p].r);
        update(p);
    }
    int rank(int x,ptr p){
        if(p==0)    return 1;
        if(x==m[p].val) return m[m[p].l].size+1;
        else if(x<m[p].val) return rank(x,m[p].l);
        else    return m[m[p].l].size+m[p].cnt+rank(x,m[p].r);
    }
    int val(int x,ptr p){
        if(p==0)    return INF;
        if(m[m[p].l].size>=x)   return val(x,m[p].l);
        else if(m[m[p].l].size+m[p].cnt>=x) return m[p].val;
        else    return val(x-m[m[p].l].size-m[p].cnt,m[p].r);
    }
    int pre(int x){
        ptr p=root;
        int ans=minfp;
        while(p){
            if(x==m[p].val){
                if(m[p].l){
                    p=m[p].l;
                    while(m[p].r)   p=m[p].r;
                    ans=p;
                }
                break;
            }
            if(m[p].val<x&&m[p].val>m[ans].val) ans=p;
            if(m[p].val>x)  p=m[p].l;
            else            p=m[p].r;
        }
        return m[ans].val;
    }
    int next(int x){
        ptr p=root;
        int ans=infp;
        while(p){
            if(x==m[p].val){
                if(m[p].r){
                    p=m[p].r;
                    while(m[p].l)   p=m[p].l;
                    ans=p;
                }
                break;
            }
            if(m[p].val>x&&m[p].val<m[ans].val) ans=p;
            if(m[p].val>x)  p=m[p].l;
            else            p=m[p].r;
        }
        return m[ans].val;
    }
    void inorder(ptr p){
        if(p==0)    return;
        inorder(m[p].l);
        printf("(ptr=%d,val=%d,l=%d,r=%d,size=%d) ",p,m[p].val,m[p].l,m[p].r,m[p].size);
        inorder(m[p].r);
    }
}t;
int main(){
    t.build();
    int n;
    scanf("%d",&n);
    while(n--){
        int op,x;
        scanf("%d%d",&op,&x);
        switch(op){
            case 1:t.insert(x,t.root);break;
            case 2:t.remove(x,t.root);break;
            case 3:printf("%d\n",t.rank(x,t.root)-1);break;
            case 4:printf("%d\n",t.val(x+1,t.root));break;
            case 5:printf("%d\n",t.pre(x));break;
            case 6:printf("%d\n",t.next(x));break;
            case 7:t.inorder(t.root);printf("\n");break;
        }
    }
    return 0;
}