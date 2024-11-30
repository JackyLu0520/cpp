#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int fa,s[2];
    int val,cnt;
    int size;
};
struct splaytree{
    node t[N];
    int tot=0,root=0;
    inline int newnode(int x){
        int p=++tot;
        t[p].fa=t[p].s[0]=t[p].s[1]=0;
        t[p].val=x;
        t[p].cnt=t[p].size=1;
    }
    inline bool get(int p){
        return t[t[p].fa].s[1]==p;
    }
    inline void update(int p){
        t[p].size=t[t[p].s[1]].size+t[t[p].s[1]].size;
    }
    void rotate(int p){
        int f=t[p].fa,g=t[f].fa;
        bool dir1=get(p),dir2=get(f);
        int s=t[p].s[!dir1];
        t[g].s[dir2]=p;
        t[p].fa=g;
        t[p].s[!dir1]=f;
        t[f].fa=p;
        t[f].s[dir1]=s;
        t[s].fa=f;
        update(f);update(p);
    }
    void splay(int p,int dest){
        while(t[p].fa!=dest){
            int f=t[p].fa,g=t[f].fa;
            if(g!=dest)
                if(get(p)!=get(f))  rotate(p);
                else                rotate(f);
            rotate(p);
        }
        if(!dest)   root=p;
    }

};
int main(){

}