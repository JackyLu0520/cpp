#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,fa[70010],val[140010],depth[140010],fa1[140010][20];
vector<int> adj[140010];
int A,B,C,P,q;
inline int rnd(){return A=(A*B+C)%P;}
const int MOD=1e9+7;
struct Edge{
    int a,b,w;
}edges[100010];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int query(int x){
    return fa[x]==x?x:query(fa[x]);
}
void dfs(int u,int pre){
    fa1[u][0]=pre;
    for(int i=1;i<=17;i++)
        fa1[u][i]=fa1[fa1[u][i-1]][i-1];
    for(int v:adj[u]){
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}
int lca(int x,int y){
    if(depth[x]<depth[y])   swap(x,y);
    int diff=depth[x]-depth[y];
    for(int i=0;diff;i++){
        if(diff&1)  x=fa1[x][i];
        diff>>=1;
    }
    if(x==y)    return x;
    for(int i=20;i>=0;i--){
        if(fa1[x][i]!=fa1[y][i]){
            x=fa1[x][i];
            y=fa1[y][i];
        }
    }
    return fa1[x][0];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].w);
    sort(edges+1,edges+m+1,cmp);
    for(int i=1;i<=(n<<1);i++)
        fa[i]=i;
    int cnt=n;
    for(int i=1;i<=m&&cnt<(n<<1)-2;i++){
        int uu=query(edges[i].a),vv=query(edges[i].b);
        if(uu!=vv){
            fa[uu]=fa[vv]=++cnt;
            val[cnt]=edges[i].w;
            adj[cnt].push_back(uu);
            adj[cnt].push_back(vv);
        }
    }
    dfs(2*n-2,0);
    scanf("%d",&q);
    scanf("%d%d%d%d",&A,&B,&C,&P);
    int ans;
    while(q--){
        int u=rnd()%n+1,v=rnd()%n+1;
        ans=(ans+val[lca(u,v)])%MOD;
    }
    printf("%d",ans);
    return 0;
}
