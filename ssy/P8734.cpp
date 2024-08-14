#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int d[2*N],dtot;
struct node{
    int l,r;
    long long tag,oddlen,evenlen;
}t[16*N];
void pushup(int p){
    if(t[p].tag){
        if(t[p].tag&1){
            t[p].evenlen=t[2*p].oddlen+t[2*p+1].oddlen;
            t[p].oddlen=d[t[p].r+1]-d[t[p].l]-t[p].evenlen;
        }else{
            t[p].oddlen=t[2*p].oddlen+t[2*p+1].oddlen;
            t[p].evenlen=d[t[p].r+1]-d[t[p].l]-t[p].oddlen;
        }
    }else{
        t[p].oddlen=t[2*p].oddlen+t[2*p+1].oddlen;
        t[p].evenlen=t[2*p].evenlen+t[2*p+1].evenlen;
    }
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].tag=0;t[p].oddlen=t[p].evenlen=0;return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);build(2*p+1,mid+1,r);
    pushup(p);
}
void add(int p,int l,int r,long long k){
    if(l<=t[p].l&&r>=t[p].r){
        t[p].tag+=k;
        pushup(p);
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  add(2*p,l,r,k);
    if(r>mid)   add(2*p+1,l,r,k);
    pushup(p);
}
/*void preorder(int p){
    printf("[%d,%d]:tag=%lld,len=%lld\n",t[p].l,t[p].r,t[p].tag,t[p].len);
    if(t[p].l!=t[p].r){preorder(2*p);preorder(2*p+1);}
}*/
struct op{
    int add,x,l,r;
    op(){}
    op(int A,int X,int L,int R){add=A;x=X;l=L;r=R;}
    bool operator < (const op& a) const{
        return x<a.x;
    }
}o[2*N];
long long oddans=0,evenans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        d[2*i-1]=x1;d[2*i]=x2;
        o[2*i-1]=op(1,min(y1,y2),min(x1,x2),max(x1,x2));
        o[2*i]=op(-1,max(y1,y2),min(x1,x2),max(x1,x2));
    }
    sort(d+1,d+2*n+1);
    dtot=unique(d+1,d+2*n+1)-d-1;
    build(1,1,dtot-1);
    sort(o+1,o+2*n+1);
    /*for(int i=1;i<=dtot;i++)
        printf("%d ",d[i]);
    printf("\n");
    for(int i=1;i<=2*n;i++)
        printf("[%d,%d] %d %d\n",o[i].l,o[i].r,o[i].x,o[i].add);
    printf("\n");
    preorder(1);*/
    for(int i=1;i<2*n;i++){
        int l=lower_bound(d+1,d+dtot+1,o[i].l)-d;
        int r=lower_bound(d+1,d+dtot+1,o[i].r)-d-1;
        add(1,l,r,o[i].add);
        oddans+=t[1].oddlen*(o[i+1].x-o[i].x);
        evenans+=t[1].evenlen*(o[i+1].x-o[i].x);
        //printf("----------[%d,%d]----------\n",l,r);
        //preorder(1);
    }
    printf("%lld\n%lld",oddans,evenans);
    return 0;
}