#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e5+10;
int n,m;
vector<int>g[N];
typedef vector<int>::iterator vit;
int fa[N][20],depth[N];

void dfs1(int u,int pre){
    fa[u][0]=pre;depth[u]=depth[pre]+1;
    for(int i=1;i<=19;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(vit it=g[u].begin();it!=g[u].end();it++)
        if(*it!=pre)
            dfs1(*it,u);
}
int lca(int u,int v){
    if(depth[u]>depth[v])   swap(u,v);
    int t=depth[v]-depth[u];
    for(int i=0;t;i++,t>>=1)
        if(t&1)  v=fa[v][i];
    if(u==v)    return u;
    for(int i=19;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];v=fa[v][i];
        }
    return fa[u][0];
}

int diff[N],s[N];
void dfs2(int u,int pre){
    for(vit it=g[u].begin();it!=g[u].end();it++)
        if(*it!=pre){
            dfs2(*it,u);
            s[u]+=s[*it];
        }
    s[u]+=diff[u];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        int w=lca(u,v);
        diff[u]++;diff[v]++;
        diff[w]--;diff[fa[w][0]]--;
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        printf("%d ",s[i]);
    return 0;
}