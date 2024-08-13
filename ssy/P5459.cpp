#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,l,r;
long long s[N]={0};
struct node{
    long long val,pri,cnt;
    int l,r;
    long long size;
};
struct Treap{
    node m[N];int tot=0;
    int root=0;
    int newnode(long long x){
        int p=++tot;
        m[p].val=x;
        m[p].size=m[p].cnt=1;
        m[p].pri=rand();
        return p;
    }
    void update(int p){
        m[p].size=m[m[p].l].size+m[m[p].r].size+m[p].cnt;
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
    void insert(long long x,int &p){
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
    long long cnt(long long x,int p){
        if(p==0)    return 0;
        if(x==m[p].val) return m[m[p].l].size+m[p].cnt;
        else if(x<m[p].val) return cnt(x,m[p].l);
        else    return m[m[p].l].size+m[p].cnt+cnt(x,m[p].r);
    }
}t;
long long ans=0;
int main(){
    srand(time(0));
    scanf("%d%d%d",&n,&l,&r);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        s[i]+=s[i-1];
    }
    t.insert(0,t.root);
    for(int i=1;i<=n;i++){
        ans+=t.cnt(s[i]-l,t.root)-t.cnt(s[i]-r-1,t.root);
        t.insert(s[i],t.root);
    }
    printf("%lld",ans);
    return 0;
}