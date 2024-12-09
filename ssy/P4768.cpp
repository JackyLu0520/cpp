#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=4e5+10,L=20;
int n,m,q,k,s;
int head[N],nxt[2*M],ver[2*M],len[2*M],tot=1;
void clear(){
    memset(head,0,sizeof(head));
    tot=1;
}
void add(int u,int v,int l){
    ver[++tot]=v;len[tot]=l;nxt[tot]=head[u];head[u]=tot;
}
int dis[N];
void dijkstra(){
    int vis[N];
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    >q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.emplace(0,1);dis[1]=0;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],l=len[i];
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
                q.emplace(dis[v],v);
            }
        }
    }
}
struct E{
    int u,v,alt;
    bool operator<(const E& a)const{
        return alt>a.alt;
    }
}e[M];
int ht[2*N],vwt[2*N],mindis[2*N],nt[2*N],vt[2*N],tt=1;
void cleart(){
    memset(ht,0,sizeof(ht));
    memset(mindis,0x3f,sizeof(mindis));
    memset(vwt,0x3f,sizeof(vwt));
    tt=1;
}
void addt(int u,int v){
    vt[++tt]=v;nt[tt]=ht[u];ht[u]=tt;
}
struct mod_dsu{
    int fa[2*N],tot=0;
    void clear(){tot=0;}
    int newnode(){tot++;fa[tot]=tot;return tot;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    int merge(int x,int y){
        int xx=query(x),yy=query(y);
        if(xx==yy)  return xx;
        return fa[xx]=fa[yy]=newnode();
    }
}d;
void kruskal(){
    cleart();
    d.clear();
    for(int i=1;i<=n;i++){
        d.newnode();
        mindis[i]=dis[i];
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int uu=d.query(e[i].u),vv=d.query(e[i].v);
        if(uu==vv)  continue;
        int f=d.merge(uu,vv);
        addt(f,uu);addt(f,vv);
        vwt[f]=e[i].alt;
        mindis[f]=min(mindis[uu],mindis[vv]);
    }
}
int fa[2*N][L];
void dfs(int u,int p){
    fa[u][0]=p;
    for(int i=1;i<L;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=ht[u];i;i=nt[i]){
        int v=vt[i];
        dfs(v,u);
    }
}
int solve(int v,int p){
    for(int i=L-1;i>=0;i--)
        if(fa[v][i]&&vwt[fa[v][i]]>p)
            v=fa[v][i];
    return v;
}
int lastans=0;
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        lastans=0;
        clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v,l,a;
            scanf("%d%d%d%d",&u,&v,&l,&a);
            add(u,v,l);
            add(v,u,l);
            e[i].u=u;e[i].v=v;e[i].alt=a;
        }
        dijkstra();
        kruskal();
        for(int i=1;i<=2*n;i++)
            if(d.query(i)==i)
                dfs(i,0);
        scanf("%d%d%d",&q,&k,&s);
        while(q--){
            int v,p;
            scanf("%d%d",&v,&p);
            v=(v+k*lastans-1)%n+1;
            p=(p+k*lastans)%(s+1);
            lastans=mindis[solve(v,p)];
            printf("%d\n",lastans);
        }
    }
    return 0;
}