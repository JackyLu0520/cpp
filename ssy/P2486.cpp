#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5+10;
int n,m;
int w[N];
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N],fa[N],depth[N];
int top[N],dfn[N],dfsid=0,rk[N];
namespace SGT{
    struct node{
        int l,r;
        int cnt,lc,rc;//count,left color,right color
        int tag;
    }t[4*N];
    inline void pushup(int p){
        t[p].lc=t[2*p].lc;
        t[p].rc=t[2*p+1].rc;
        t[p].cnt=t[2*p].cnt+t[2*p+1].cnt;
        if(t[2*p].rc==t[2*p+1].lc)
            t[p].cnt--;
    }
    inline void maketag(int p,int k){
        t[p].tag=k;
        t[p].cnt=1;
        t[p].lc=t[p].rc=k;
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
        if(l==r){
            t[p].cnt=1;
            t[p].lc=t[p].rc=w[rk[l]];
            return;
        }
        int mid=(l+r)/2;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
        pushup(p);
    }
    void color(int p,int l,int r,int k){
        if(t[p].l>=l&&t[p].r<=r){
            maketag(p,k);
            return;
        }
        pushdown(p);
        int mid=(t[p].l+t[p].r)/2;
        if(l<=mid)  color(2*p,l,r,k);
        if(r>mid)   color(2*p+1,l,r,k);
        pushup(p);
    }
    void query(int p,int l,int r,int &_lc,int &_rc,int &_cnt){
        if(t[p].l>=l&&t[p].r<=r){
            _lc=t[p].lc;
            _rc=t[p].rc;
            _cnt=t[p].cnt;
            return;
        }
        pushdown(p);
        int mid=(t[p].l+t[p].r)/2;
        if(r<=mid)  query(2*p,l,r,_lc,_rc,_cnt);
        else if(l>mid)  query(2*p+1,l,r,_lc,_rc,_cnt);
        else{
            int mlc,mrc,cnt1,cnt2;
            query(2*p,l,r,_lc,mlc,cnt1);
            query(2*p+1,l,r,mrc,_rc,cnt2);
            _cnt=cnt1+cnt2;
            if(mlc==mrc)    _cnt--;
        }
    }
#ifdef DEBUG
    void printall(){
        for(int i=1;i<=n;i++){
            int lc,rc,cnt;
            query(1,i,i,lc,rc,cnt);
            printf("%d ",lc);
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
                int l,r;
                scanf("%d%d",&l,&r);
                int lc,rc,cnt;
                query(1,l,r,lc,rc,cnt);
                printf("lc=%d,rc=%d,cnt=%d\n",lc,rc,cnt);
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
            if(size[v]>maxsize)
                maxsize=size[v],son[u]=v;
        }
    }
    void dfs2(int u,int p){
        if(u==son[p])   top[u]=top[p];
        else            top[u]=u;
        dfn[u]=++dfsid;rk[dfsid]=u;
        if(son[u])
            dfs2(son[u],u);
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
        SGT::color(1,dfn[u],dfn[v],k);
    }
    int query(int u,int v){
        int preulc=-1,prevlc=-1,ans=0;
        while(top[u]!=top[v]){
            int lc,rc,cnt;
            if(depth[top[u]]>depth[top[v]]){
                SGT::query(1,dfn[top[u]],dfn[u],lc,rc,cnt);
                ans+=cnt;
                if(rc==preulc)  ans--;
                preulc=lc;
                u=fa[top[u]];
            }else{
                SGT::query(1,dfn[top[v]],dfn[v],lc,rc,cnt);
                ans+=cnt;
                if(rc==prevlc)  ans--;
                prevlc=lc;
                v=fa[top[v]];
            }
        }
        if(depth[u]>depth[v])   swap(u,v),swap(preulc,prevlc);
        int lc,rc,cnt;
        SGT::query(1,dfn[u],dfn[v],lc,rc,cnt);
        ans+=cnt;
        if(lc==preulc)  ans--;
        if(rc==prevlc)  ans--;
        return ans;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
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
        printf("%d:size=%d,son=%d,fa=%d,depth=%d,top=%d,dfn=%d\n",i,size[i],son[i],fa[i],depth[i],top[i],dfn[i]);
    for(int i=1;i<=n;i++)
        printf("%d ",rk[i]);
    printf("\n");
    SGT::terminal();
#else
    while(m--){
        char op;
        scanf(" %c",&op);
        if(op=='C'){
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
            HLD::color(u,v,k);
        }else{
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",HLD::query(u,v));
        }
    }
#endif
    return 0;
}