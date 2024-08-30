#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
struct node{
    int val,cnt,pri;
    int ls,rs;
    int size;
};
struct tuple3{
    int first,second,third;
    tuple3(){}
    tuple3(int a,int b,int c){first=a,second=b,third=c;}
};
struct FHQTreap{
    node a[N];int tot=0,root=0;
    int newnode(int x){
        int p=++tot;
        a[p].val=x;a[p].pri=Rand();
        a[p].cnt=a[p].size=1;
        return p;
    }
    void update(int p){
        a[p].size=a[p].cnt+a[a[p].ls].size+a[a[p].rs].size;
    }
    pair<int,int> splitbyval(int p,int val){
        if(!p)  return make_pair(0,0);
        if(a[p].val<=val){
            pair<int,int>t=splitbyval(a[p].rs,val);
            a[p].rs=t.first;
            update(p);
            return make_pair(p,t.second);
        }else{
            pair<int,int>t=splitbyval(a[p].ls,val);
            a[p].ls=t.second;
            update(p);
            return make_pair(t.first,p);
        }
    }
    int merge(int p,int q){
        if(!p&&!q)  return 0;
        if(!p&&q)   return q;
        if(p&&!q)   return p;
        if(a[p].pri>a[q].pri){
            a[q].ls=merge(p,a[q].ls);
            update(q);
            return q;
        }else{
            a[p].rs=merge(a[p].rs,q);
            update(p);
            return p;
        }
    }
    void insert(int x){
        pair<int,int>r=splitbyval(root,x);
        pair<int,int>l=splitbyval(r.first,x-1);
        if(l.second){
            a[l.second].cnt++;
            update(l.second);
        }else{
            l.second=newnode(x);
        }
        root=merge(merge(l.first,l.second),r.second);
    }
    void remove(int x){
        pair<int,int>r=splitbyval(root,x);
        pair<int,int>l=splitbyval(r.first,x-1);
        if(a[l.second].cnt>1){
            a[l.second].cnt--;
            update(l.second);
            l.first=merge(l.first,l.second);
        }else
            l.second=0;
        root=merge(l.first,r.second);
    }
    int rank(int val){
        pair<int,int>t=splitbyval(root,val-1);
        int ret=a[t.first].size+1;
        root=merge(t.first,t.second);
        return ret;
    }
};