#include<bits/stdc++.h>
using namespace std;
struct node{
    int val,cnt,pri;
    int l,r;
    int size;
};
struct Treap{
    node a[1000010];int tot;
    stack<int>free;
    int root;
    int alloc(){
        if(free.empty())    return ++tot;
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
    int newnode(int x,int cnt){
        int p=alloc();
        a[p].val=x;
        a[p].size=a[p].cnt=x;
        a[p].pri=rand();
        a[p].l=a[p].r=0;
        return p;
    }
    void update(int p){
        a[p].size=a[a[p].l].size+a[a[p].r].size+a[p].cnt;
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
    void insert(int x,int cnt){
        pair<int,int> r=splitbyval(x,root);
        pair<int,int> l=splitbyval(x-1,r.first);
        if(l.second==0){
            root=merge(merge(l.first,newnode(x,cnt)),r.second);
        }else{
            a[l.second].cnt+=cnt;
            update(l.second);
            root=merge(merge(l.first,l.second),r.second);
        }
    }
    void remove(int l,int r){
        pair<int,int> rt=splitbyval(r,root);
        pair<int,int> lt=splitbyval(l-1,rt.first);
        
    }
};
int main(){

}