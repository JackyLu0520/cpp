#include<bits/stdc++.h>
using namespace std;
const int M=3e5+10;
struct fastio{
    char in[1<<20],*p1,*p2;
    char out[1<<20],*p3;
    fastio(){p1=in,p2=in,p3=out;}
    ~fastio(){fwrite(out,1,p3-out,stdout);}
    inline char getchar(){
        return (p1==p2&&(p2=(p1=in)+fread(in,1,1<<20,stdin),p1==p2))?EOF:*p1++;
    }
    inline void putchar(const char &c){
        p3-out==(1<<20)?fwrite(out,1,1<<20,stdout),p3=out,*p3++=c:*p3++=c;
    }
}io;
#define getchar io.getchar
#define putchar io.putchar
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
    int ls,rs;
}t[M*50];int tot=0;
int root;
inline int newnode(int l,int r){
    int p=++tot;
    t[p].sum=r-l+1;
    t[p].tag=-1;
    t[p].ls=t[p].rs=0;
    return p;
}
inline void pushup(int p,int l,int r){
    int mid=(l+r)/2;
    if(t[p].ls==0)  t[p].ls=newnode(l,mid);
    if(t[p].rs==0)  t[p].rs=newnode(mid+1,r);
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
inline void maketag(int &p,bool k,int l,int r){
    if(p==0)  p=newnode(l,r);
    t[p].sum=(r-l+1)*k;
    t[p].tag=k;
}
inline void pushdown(int p,int l,int r){
    if(t[p].tag!=-1){
        int mid=(l+r)/2;
        maketag(t[p].ls,t[p].tag,l,mid);
        maketag(t[p].rs,t[p].tag,mid+1,r);
        t[p].tag=-1;
    }
}
void overwrite(int &p,int l,int r,bool k,int pl,int pr){
    if(p==0)  p=newnode(pl,pr);
    if(pl>=l&&pr<=r){
        maketag(p,k,pl,pr);
        return;
    }
    pushdown(p,pl,pr);
    int mid=(pl+pr)/2;
    if(l<=mid)  overwrite(t[p].ls,l,r,k,pl,mid);
    if(r>mid)   overwrite(t[p].rs,l,r,k,mid+1,pr);
    pushup(p,pl,pr);
}
int main(){
    n=read(),q=read();
    while(q--){
        int l,r,k;
        l=read(),r=read(),k=read();
        overwrite(root,l,r,k-1,1,n);
        write(t[root].sum);
        putchar('\n');
    }
    return 0;
}