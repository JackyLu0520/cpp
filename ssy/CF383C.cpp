#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
inline int lowbit(int x){
    return x&(-x);
}
struct BIT{
    int c[N]={0};
    void add(int i,int k){
        for(;i<=n;i+=lowbit(i))
            c[i]+=k;
    }
    int query(int i){
        int ans=0;
        for(;i;i-=lowbit(i))
            ans+=c[i];
        return ans;
    }
}bit;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int l[N],r[N],dfsid;
int depth[N];
void dfs(int u,int p){
    l[u]=++dfsid;depth[u]=depth[p]+1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v!=p)
            dfs(v,u);
    }
    r[u]=dfsid;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    /*for(int i=1;i<=n;i++)
        fprintf(stderr,"%d ",l[i]);
    fprintf(stderr,"\n");
    for(int i=1;i<=n;i++)
        fprintf(stderr,"%d ",depth[i]);
    fprintf(stderr,"\n");*/
    for(int i=1;i<=m;i++){
        int op;scanf("%d",&op);
        if(op==1){
            int u,val;scanf("%d%d",&u,&val);
            if(depth[u]&1)  val=-val;
            bit.add(l[u],val);
            bit.add(r[u]+1,-val);
        }else{
            int u;scanf("%d",&u);
            int d=bit.query(l[u]);
            if(depth[u]&1)  d=-d;
            printf("%d\n",d+a[u]);
        }
    }
    return 0;
}