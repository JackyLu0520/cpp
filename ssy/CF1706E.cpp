#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=2e5+10,L=18;
int n,m,q;
struct E{
    int u,v;
}e[M];
int fa[2*N][L],vw[2*N],depthm[2*N];
struct mod_dsu{
    int fa[2*N],tot=0;
    inline void clear(){tot=0;}
    inline int newnode(){tot++;fa[tot]=tot;return tot;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    inline int merge(int x,int y){
        int xx=query(x),yy=query(y);
        if(xx==yy)  return xx;
        return fa[xx]=fa[yy]=newnode();
    }
}d;
inline void kruskal(){
    d.clear();
    for(int i=1;i<=n;i++){
        d.newnode();
        vw[i]=0;
    }
    for(int i=1;i<=m;i++){
        int uu=d.query(e[i].u),vv=d.query(e[i].v);
        if(uu==vv)continue;
        int f=d.merge(uu,vv);
        fa[uu][0]=f;fa[vv][0]=f;
        vw[f]=i;
    }
    for(int i=2*n;i>=1;i--)
        for(int j=1;j<=n;j++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
}
inline int depth(int u){
    /*
    if(u==0)    return 0;
    if(depthm[u])    return depthm[u];
    return depthm[u]=depth(fa[u][0])+1;
    */
    stack<int>stk;
    int t=u;
    while(!depthm[t]&&t){
        stk.push(t);
        t=fa[t][0];
    }
    while(!stk.empty()){
        depthm[stk.top()]=depthm[t]+1;
        t=stk.top();
        stk.pop();
    }
    return depthm[u];
}
int lca(int u,int v){
    if(depth(u)<depth(v))swap(u,v);
    int t=depth(u)-depth(v);
    for(int i=0;t;i++){
        if(t&1) u=fa[u][i];
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
int lg[N];
inline void prework_lg(){
    lg[1]=0;
    for(int i=2;i<N;i++)
        lg[i]=lg[i>>1]+1;
}
struct lca_st{
    int st[N][L];
    inline void build(){
        for(int i=1;i<=n;i++)
            st[i][0]=i;
        for(int j=1;j<L;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                st[i][j]=lca(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
    inline int query(int l,int r){
        int t=lg[r-l+1];
        int a=st[l][t];
        int b=st[r-(1<<t)+1][t];
        return lca(a,b);
    }
}st;
signed main(){
    prework_lg();
    int _;
    scanf("%lld",&_);
    while(_--){
        scanf("%lld%lld%lld",&n,&m,&q);
        for(int i=1;i<=m;i++)
            scanf("%lld%lld",&e[i].u,&e[i].v);
        kruskal();
        for(int i=1;i<=2*n;i++)
            depthm[i]=0;
        st.build();
        while(q--){
            int l,r;
            scanf("%lld%lld",&l,&r);
            printf("%lld ",vw[st.query(l,r)]);
#ifdef DEBUG
            int ans=l;
            for(int i=l+1;i<=r;i++)
                ans=lca(ans,i);
            printf("(%lld) ",vw[ans]);
#endif
        }
        printf("\n");
    }
    return 0;
}