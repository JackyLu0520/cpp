#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long M=5e5+10,MOD=998244353;
struct node{
    int val,pri;long long cnt;
    int l,r;
    long long size;
};
struct Treap{
    vector<node> a;int tot=0;
    stack<int>free;
    int root=0;
    Treap(){a.push_back(node());}
    int alloc(){
        if(free.empty()){
            a.push_back(node());
            return ++tot;
        }
        else{
            int p=free.top();free.pop();
            if(a[p].l)  free.push(a[p].l);
            if(a[p].r)  free.push(a[p].r);
            return p;
        }
    }
    void del(int p){
        free.push(p);
    }
    int newnode(int x,long long cnt){
        int p=alloc();
        a[p].val=x;
        a[p].size=a[p].cnt=cnt%MOD;
        a[p].pri=rand();
        a[p].l=a[p].r=0;
        return p;
    }
    void update(int p){
        a[p].size=((a[a[p].l].size+a[a[p].r].size)%MOD+a[p].cnt)%MOD;
    }
    pair<int,int> splitbyval(int x,int p){
        if(p==0)    return make_pair(0,0);
        if(a[p].val<=x){
            pair<int,int> t=splitbyval(x,a[p].r);
            a[p].r=t.first;
            update(p);
            return make_pair(p,t.second);
        }else{
            pair<int,int> t=splitbyval(x,a[p].l);
            a[p].l=t.second;
            update(p);
            return make_pair(t.first,p);
        }
    }
    int merge(int p,int q){
        if(p==0&&q==0)  return 0;
        if(p!=0&&q==0)  return p;
        if(p==0&&q!=0)  return q;
        if(a[p].pri<a[q].pri){
            a[p].r=merge(a[p].r,q);
            update(p);
            return p;
        }else{
            a[q].l=merge(p,a[q].l);
            update(q);
            return q;
        }
    }
    void insert(int x,long long cnt){
        pair<int,int> r=splitbyval(x,root);
        pair<int,int> l=splitbyval(x-1,r.first);
        if(l.second==0){
            root=merge(merge(l.first,newnode(x,cnt)),r.second);
        }else{
            a[l.second].cnt=(a[l.second].cnt+cnt)%MOD;
            update(l.second);
            root=merge(merge(l.first,l.second),r.second);
        }
    }
    void remove(int l,int r){
        pair<int,int> rt=splitbyval(r,root);
        pair<int,int> lt=splitbyval(l-1,rt.first);
        del(lt.second);
        root=merge(lt.first,rt.second);
    }
    long long cnt(int x,int p){
        if(p==0)    return 0;
        if(x==a[p].val) return (a[a[p].l].size+a[p].cnt)%MOD;
        else if(x<a[p].val) return cnt(x,a[p].l)%MOD;
        else    return ((a[a[p].l].size+a[p].cnt)%MOD+cnt(x,a[p].r))%MOD;
    }
    long long size(){
        return a[root].size%MOD;
    }
}t;
struct land{
    int l,r,h;
    bool operator < (const land& a) const{
        return h>a.h;
    }
}l[M];
int n,m;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&l[i].l,&l[i].r,&l[i].h);
    sort(l+1,l+m+1);
    for(int i=1;i<=n;i++){
        int x;scanf("%lld",&x);
        t.insert(x,1);
    }
    for(int i=1;i<=m;i++){
        long long cnt=(t.cnt(l[i].r,t.root)%MOD-t.cnt(l[i].l-1,t.root)%MOD)%MOD;
        t.remove(l[i].l,l[i].r);
        t.insert(l[i].l,cnt);t.insert(l[i].r,cnt);
    }
    printf("%lld",t.size());
    return 0;
}