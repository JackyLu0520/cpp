#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,L=22;
int n;
int ls[2*N]={0},rs[2*N]={0};
int vtot=0,rt;
struct node{
    int sum;
    int ls,rs;
}t[N*L];int tot=0;
int root[2*N];
inline void pushup(int p){
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
void add(int &p,int i,int k,int pl,int pr){
    if(!p)  p=++tot,t[p].sum=0;
    if(pl==pr){
        t[p].sum+=k;
        return;
    }
    int mid=(pl+pr)/2;
    if(i<=mid)  add(t[p].ls,i,k,pl,mid);
    else        add(t[p].rs,i,k,mid+1,pr);
    pushup(p);
}
long long ans=0,x,y;
int merge(int p,int q,int l,int r){
    if(!p||!q)  return p+q;
    if(l==r){
        t[p].sum+=t[q].sum;
        return p;
    }
    x+=1ll*t[t[p].ls].sum*t[t[q].rs].sum;
    y+=1ll*t[t[p].rs].sum*t[t[q].ls].sum;
    int mid=(l+r)/2;
    t[p].ls=merge(t[p].ls,t[q].ls,l,mid);
    t[p].rs=merge(t[p].rs,t[q].rs,mid+1,r);
    pushup(p);
    return p;
}
int read(){
    int u=++vtot;
    int tmp;
    scanf("%d",&tmp);
    if(tmp!=0){
        add(root[u],tmp,1,1,n);
    }else{
        ls[u]=read();
        rs[u]=read();
    }
    return u;
}
void dfs(int u){
    if(ls[u]==0&&rs[u]==0)  return;
    dfs(ls[u]);
    dfs(rs[u]);
    x=y=0;
    root[u]=merge(root[ls[u]],root[rs[u]],1,n);
    ans+=min(x,y);
}
#ifdef DEBUG
void print(int u,int d){
    if(!u)  return;
    for(int i=1;i<=d;i++)
        printf(" ");
    printf("o\n");
    print(ls[u],d+1);
    print(rs[u],d+1);
}
#endif
int main(){
    scanf("%d",&n);
    rt=read();
#ifdef DEBUG
    print(rt,0);
#endif
    dfs(rt);
    printf("%lld",ans);
    return 0;
}