#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10,M=4e5+10,L=22;
int n,m,q;
struct E{
    int u,v,w,id;
    inline bool operator<(const E& a)const{
        return w>a.w;
    }
}e[M];
struct mod_dsu{
    int fa[2*N],tot=0;
    int newnode(){tot++;fa[tot]=tot;return tot;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    int merge(int x,int y){
        int xx=query(x),yy=query(y);
        if(xx==yy)  return xx;
        return fa[xx]=fa[yy]=newnode();
    }
}d;
int head[2*N],vw[2*N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int id[M];
void kruskal(){
    for(int i=1;i<=n;i++)
        d.newnode();
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int uu=d.query(e[i].u),vv=d.query(e[i].v);
        if(uu!=vv){
            int f=d.merge(uu,vv);
            add(f,uu);add(f,vv);
            vw[f]=e[i].w;
            id[e[i].id]=f;
        }
    }
    vw[0]=-1;
}
int fa[2*N][L],depth[2*N],size[2*N];
void dfs(int u,int p){
    fa[u][0]=p;depth[u]=depth[p]+1;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        dfs(v,u);
        size[u]+=size[v];
    }
    if(!size[u])    size[u]=1;
}
int lim=0;
int search(int u){
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]&&vw[fa[u][i]]>=lim)
            u=fa[u][i];
    return u;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        e[i].id=i;
    }
    kruskal();
    for(int i=1;i<=2*n;i++)
        if(d.query(i)==i)
            dfs(i,0);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&lim);
        }else if(op==2){
            int x;scanf("%d",&x);
            printf("%d\n",size[search(x)]);
        }else{
            int x,y;scanf("%d%d",&x,&y);
            vw[id[x]]=y;
        }
    }
    return 0;
}