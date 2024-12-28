#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int sgn=1,n=0;
    char c;
    do{c=getchar();if(c=='-')sgn=-1;}while(!isdigit(c));
    while(isdigit(c)){
        n=(n<<1)+(n<<3)+c-'0';
        c=getchar();
    }
    return sgn*n;
}
void write(int n,bool f=1){
    if(n<0){putchar('-');n=-n;}
    if(n==0){
        if(f)   putchar('0');
        return;
    }
    write(n/10,0);
    putchar(n%10+'0');
}
int n,q;
struct node{
    int sum;
    short tag;
    node *ls,*rs;
};
node *root;
inline node *newnode(int l,int r){
    node *p=new node;
    p->sum=r-l+1;
    p->tag=-1;
    p->ls=p->rs=nullptr;
    return p;
}
inline void pushup(node *p,int l,int r){
    int mid=(l+r)/2;
    if(p->ls==nullptr)  p->ls=newnode(l,mid);
    if(p->rs==nullptr)  p->rs=newnode(mid+1,r);
    p->sum=p->ls->sum+p->rs->sum;
}
inline void maketag(node *&p,bool k,int l,int r){
    if(p==nullptr)  p=newnode(l,r);
    p->sum=(r-l+1)*k;
    p->tag=k;
}
inline void pushdown(node *p,int l,int r){
    if(p->tag!=-1){
        int mid=(l+r)/2;
        maketag(p->ls,p->tag,l,mid);
        maketag(p->rs,p->tag,mid+1,r);
        p->tag=-1;
    }
}
void overwrite(node *&p,int l,int r,bool k,int pl,int pr){
    if(p==nullptr)  p=newnode(pl,pr);
    if(pl>=l&&pr<=r){
        maketag(p,k,pl,pr);
        return;
    }
    pushdown(p,pl,pr);
    int mid=(pl+pr)/2;
    if(l<=mid)  overwrite(p->ls,l,r,k,pl,mid);
    if(r>mid)   overwrite(p->rs,l,r,k,mid+1,pr);
    pushup(p,pl,pr);
}
int main(){
    n=read(),q=read();
    while(q--){
        int l,r,k;
        l=read(),r=read(),k=read();
        overwrite(root,l,r,k-1,1,n);
        write(root->sum);
        putchar('\n');
    }
    return 0;
}