#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
struct seg{
    long long l,r,d;//l,l+d,l+2d,...,r
    seg(){l=1,r=0,d=1;}
    seg(long long _l,long long _r,long long _d){
        l=_l,r=_r,d=_d;
    }
    inline int size(){
        return (r-l)/d+1;
    }
    inline void split(int i,seg &L,long long &M,seg &R){
        L=seg(l,l+(i-2)*d,d);
        M=l+(i-1)*d;
        R=seg(l+i*d,r,d);
    }
    inline bool empty(){
        return l>r;
    }
    //debug
    /*void print(){
        for(long long i=l;i<=r;i+=d)
            printf("%lld ",i);
    }*/
    //
};
struct node{
    seg val;
    int pri;
    int size;
    int ls,rs;
    node(){val=seg(1,0,1),pri=Rand(),size=0,ls=0,rs=0;}
    node(seg x){val=x,pri=Rand(),size=x.size(),ls=0,rs=0;}
};
vector<node>t(1);
queue<int>q;
struct tree{
    int root=0;
    inline int newnode(seg x){
        if(x.empty())   return 0;
        int p;
        if(q.empty()){
            t.emplace_back();
            p=t.size()-1;
        }else{
            p=q.front();q.pop();
        }
        t[p]=node(x);
        return p;
    }
    void update(int p){
        t[p].size=t[t[p].ls].size+t[t[p].rs].size+t[p].val.size();
    }
    void split(int p,int i,int &l,int &mid,int &r){//p ---rank:i--> l,mid,r
        if(!p){
            l=mid=r=0;
        }else if(t[t[p].ls].size>=i){
            r=p;
            split(t[p].ls,i,l,mid,t[p].ls);
        }else if(t[t[p].ls].size+t[p].val.size()>=i){
            l=t[p].ls,mid=p,r=t[p].rs;
            t[p].ls=t[p].rs=0;
        }else{
            l=p;
            split(t[p].rs,i-t[t[p].ls].size-t[p].val.size(),t[p].rs,mid,r);
        }
        update(p);
    }
    int merge(int l,int r){
        if(!l||!r)  return l+r;
        if(t[l].pri<t[r].pri){
            t[l].rs=merge(t[l].rs,r);
            update(l);
            return l;
        }else{
            t[r].ls=merge(l,t[r].ls);
            update(r);
            return r;
        }
    }
    long long remove(int i){
        int L,M,R;
        split(root,i,L,M,R);
        seg l,r;long long mid;
        t[M].val.split(i-t[L].size,l,mid,r);
        q.push(M);
        int LL=newnode(l),RR=newnode(r);
        root=merge(merge(L,merge(LL,RR)),R);
        return mid;
    }
    void pushback(seg x){
        root=merge(root,newnode(x));
    }
    //debug
    /*void inorder(int p){
        if(!p)  return;
        inorder(t[p].ls);
        t[p].val.print();
        inorder(t[p].rs);
    }*/
    //
}row[N],col;
int n,m,_;
int main(){
    scanf("%d%d%d",&n,&m,&_);
    for(int i=1;i<=n;i++)
        row[i].pushback(seg(1ll*(i-1)*m+1,1ll*i*m-1,1));
    col.pushback(seg(m,1ll*n*m,m));
    while(_--){
        int x,y;scanf("%d%d",&x,&y);
        if(y==m){
            long long tmp=col.remove(x);
            col.pushback(seg(tmp,tmp,m));
            printf("%lld\n",tmp);
            continue;
        }
        long long tmp1=row[x].remove(y);
        long long tmp2=col.remove(x);
        row[x].pushback(seg(tmp2,tmp2,1));
        col.pushback(seg(tmp1,tmp1,m));
        printf("%lld\n",tmp1);
        //debug
        /*printf("row:\n");
        for(int i=1;i<=n;i++){
            row[i].inorder(row[i].root);
            putchar('\n');
        }
        printf("col:\n");
        col.inorder(col.root);
        putchar('\n');*/
        //
    }
    return 0;
}