#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> E;
const int N=5e4+10,M=5e4+10;
int n,m;
int head[N],nxt[2*N],ver[2*N],tot=1;
inline void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N],fa[N],depth[N],ev[2*N],rk[N];
int top[N],dfn[N],dfsid=0;
namespace SGT{
    struct node{
        int l,r;
        int tag;
    }t[4*N];
    inline void maketag(int p,int k){
        t[p].tag=k;
    }
    inline void pushdown(int p){
        if(t[p].tag!=-1){
            maketag(2*p,t[p].tag);
            maketag(2*p+1,t[p].tag);
            t[p].tag=-1;
        }
    }
    void build(int p,int l,int r){
        t[p].l=l;t[p].r=r;t[p].tag=-1;
        if(l==r)    return;
        int mid=(l+r)/2;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
    }
    void color(int p,int l,int r,int k){
        if(l>r) return;
        if(t[p].l>=l&&t[p].r<=r){
            maketag(p,k);
            return;
        }
        pushdown(p);
        int mid=(t[p].l+t[p].r)/2;
        if(l<=mid)  color(2*p,l,r,k);
        if(r>mid)   color(2*p+1,l,r,k);
    }
    int query(int p,int i){
        if(t[p].l==t[p].r)
            return t[p].tag;
        pushdown(p);
        int mid=(t[p].l+t[p].r)/2;
        if(i<=mid)  return query(2*p,i);
        else        return query(2*p+1,i);
    }
#ifdef DEBUG
    void printall(){
        for(int i=1;i<=n;i++){
            printf("%d ",query(1,i));;
        }
        printf("\n");
    }
    void terminal(){
        printf("Segment Tree Terminal\n");
        printall();
        while(1){
            printf(">");
            char op;
            scanf(" %c",&op);
            if(op=='C'){
                int l,r,k;
                scanf("%d%d%d",&l,&r,&k);
                color(1,l,r,k);
            }else if(op=='Q'){
                int i;
                scanf("%d",&i);
                printf("%d\n",query(1,i));
            }else if(op=='P')
                printall();
            else if(op=='X')
                break;
        }
    }
#endif
}
namespace HLD{
    void dfs1(int u,int p){
        size[u]=1;son[u]=0;
        fa[u]=p;depth[u]=depth[p]+1;
        int maxsize=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p)    continue;
            dfs1(v,u);
            size[u]+=size[v];
            if(maxsize<size[v])
                maxsize=size[v],son[u]=v;
            ev[i]=ev[i^1]=v;
        }
    }
    void dfs2(int u,int p){
        if(u==son[p])   top[u]=top[p];
        else            top[u]=u;
        dfn[u]=++dfsid;rk[dfsid]=u;
        if(son[u])  dfs2(son[u],u);
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(v==p||v==son[u]) continue;
            dfs2(v,u);
        }
    }
    void color(int u,int v,int k){
        while(top[u]!=top[v]){
            if(depth[top[u]]>depth[top[v]]){
                SGT::color(1,dfn[top[u]],dfn[u],k);
                u=fa[top[u]];
            }else{
                SGT::color(1,dfn[top[v]],dfn[v],k);
                v=fa[top[v]];
            }
        }
        if(depth[u]>depth[v])   swap(u,v);
        SGT::color(1,dfn[u]+1,dfn[v],k);
#ifdef DEBUG
        SGT::printall();
#endif
    }
}
E e[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    HLD::dfs1(1,0);
    HLD::dfs2(1,0);
    SGT::build(1,1,n);
#ifdef DEBUG
    for(int i=1;i<=n;i++)
        printf("%d ",rk[i]);
    printf("\n");
#endif
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i]=make_tuple(u,v,w);
    }
    sort(e+1,e+m+1,[](E a,E b){return (get<2>(a))>(get<2>(b));});
    for(int i=1;i<=m;i++){
        int u,v,w;
        tie(u,v,w)=e[i];
        HLD::color(u,v,w);
    }
    for(int i=2;i<=tot;i+=2)
        printf("%d\n",SGT::query(1,dfn[ev[i]]));
    return 0;
}