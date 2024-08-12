#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,INF=0x3f3f3f3f;
int n,m,a[N]={0};
struct node{
    int val,cnt,pri;
    int l,r;
    long long size,sum;
};
struct Treap{
    node m[N];int tot=0;
    int root=0;
    int newnode(int x,long long cnt){
        int p=++tot;
        m[p].val=x;
        m[p].size=m[p].cnt=cnt;
        m[p].sum=cnt*x;
        m[p].pri=rand();
        return p;
    }
    void update(int p){
        m[p].size=m[m[p].l].size+m[m[p].r].size+m[p].cnt;
        m[p].sum=m[m[p].l].sum+m[m[p].r].sum+m[p].cnt*m[p].val;
    }
    void zig(int &p){
        int t=m[p].l;
        m[p].l=m[t].r;
        m[t].r=p;p=t;
        update(m[p].r);update(p);
    }
    void zag(int &p){
        int t=m[p].r;
        m[p].r=m[t].l;
        m[t].l=p;p=t;
        update(m[p].l);update(p);
    }
    void insert(int x,long long cnt,int &p){
        if(p==0){p=newnode(x,cnt);return;}
        if(m[p].val==x){m[p].cnt+=cnt;update(p);return;}
        if(x<m[p].val){
            insert(x,cnt,m[p].l);
            if(m[p].pri<m[m[p].l].pri)    zig(p);
        }
        else{
            insert(x,cnt,m[p].r);
            if(m[p].pri<m[m[p].r].pri)    zag(p);
        }
        update(p);
    }
    void remove(int x,int &p){
        if(p==0)    return;
        if(x==m[p].val){
            if(m[p].cnt>1){
                m[p].cnt--;update(p);
                return;
            }
            if(m[p].l||m[p].r){
                if(!m[p].r||m[m[p].l].pri>m[m[p].r].pri)
                    zig(p),remove(x,m[p].r);
                else
                    zag(p),remove(x,m[p].l);
                update(p);
            }else   p=0;
            return;
        }
        if(x<m[p].val)  remove(x,m[p].l);
        else            remove(x,m[p].r);
        update(p);
    }
    long long cnt(int x,int p){
        if(p==0)    return 0;
        if(x==m[p].val) return m[m[p].l].size+m[p].cnt;
        else if(x<m[p].val) return cnt(x,m[p].l);
        else    return m[m[p].l].size+m[p].cnt+cnt(x,m[p].r);
    }
    long long sum(int x,int p){
        if(p==0)    return 0;
        if(x==m[p].val) return m[m[p].l].sum+m[p].cnt*m[p].val;
        else if(x<m[p].val) return sum(x,m[p].l);
        else    return m[m[p].l].sum+m[p].cnt*m[p].val+sum(x,m[p].r);
    }
}t2;
int main(){
    scanf("%d%d",&n,&m);
    t2.insert(0,n,t2.root);
    while(m--){
        char op[3];long long x,y;
        scanf("%s%lld%lld",&op,&x,&y);
        if(op[0]=='U'){
            t2.remove(a[x],t2.root);t2.insert(y,1,t2.root);
            a[x]=y;
        }else{
            if(t2.sum(y,t2.root)+(n-t2.cnt(y,t2.root))*y>=x*y) printf("TAK\n");
            else                                    printf("NIE\n");
        }
    }
    return 0;
}