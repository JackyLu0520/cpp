#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,w,h;
int d[2*N],dtot;
struct node{
    int l,r;
    long long tag,mx;
}t[16*N];
void pushup(int p){
    t[p].mx=max(t[2*p].mx,t[2*p+1].mx)+t[p].tag;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){t[p].tag=0;t[p].mx=0;return;}
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
    printf("[%d,%d]:tag=%lld,mx=%lld\n",t[p].l,t[p].r,t[p].tag,t[p].mx);
    if(t[p].l!=t[p].r){preorder(2*p);preorder(2*p+1);}
}*/
struct op{
    int add,x,l,r;
    op(){}
    op(int A,int X,int L,int R){add=A;x=X;l=L;r=R;}
    bool operator < (const op& a) const{
        return x==a.x?add<a.add:x<a.x;
    }
}o[2*N];
long long ans;
int main(){
    int m;
    scanf("%d",&m);
    while(m--){
        scanf("%d%d%d",&n,&w,&h);
        for(int i=1;i<=n;i++){
            int x1,y1,x2,y2,l;
            scanf("%d%d%d",&x1,&y1,&l);
            x2=x1+w,y2=y1+h;
            d[2*i-1]=x1;d[2*i]=x2;
            o[2*i-1]=op(l,y1,x1,x2);
            o[2*i]=op(-l,y2,x1,x2);
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
        ans=0;
        for(int i=1;i<=2*n;i++){
            int l=lower_bound(d+1,d+dtot+1,o[i].l)-d;
            int r=lower_bound(d+1,d+dtot+1,o[i].r)-d-1;
            add(1,l,r,o[i].add);
            ans=max(ans,t[1].mx);
            //printf("----------[%d,%d]----------\n",l,r);
            //preorder(1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}