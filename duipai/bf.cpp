#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;const int N=1e5+10;typedef long long ll;
int n;int m;int v[2*N];int x[2*N];int ct;int al[N];int fa[N][22];int dep[N];int ans[N];
struct data//存最大值的结构体 
{
    int u;int cnt;
    friend bool operator <(data a,data b){return (a.cnt==b.cnt)?a.u>b.u:a.cnt<b.cnt;}
    friend data operator +(data a,data b){return (data){a.u,a.cnt+b.cnt};}
};vector <data> ve[N];
inline void add(int u,int V){v[++ct]=V;x[ct]=al[u];al[u]=ct;}
struct linetree//动态开点线段树合并 
{
    int s[40*N][2];data v[40*N];int ct;
    inline void ih(){ct=n;}
    inline void ins(int p,int l,int r,data va)//插入 
    {
        if(r-l==1){v[p]=va+v[p];return;}int mid=(l+r)/2;
        if(va.u<=mid)ins(s[p][0]=s[p][0]?s[p][0]:++ct,l,mid,va);
        else ins(s[p][1]=s[p][1]?s[p][1]:++ct,mid,r,va);v[p]=max(v[s[p][0]],v[s[p][1]]);
    }
    inline void mg(int p1,int p2,int l,int r)//合并 
    {
        if(r-l==1){v[p1]=v[p1]+v[p2];return;}int mid=(l+r)/2;//分情况讨论下 
        if(s[p1][0]&&s[p2][0])mg(s[p1][0],s[p2][0],l,mid);else if(s[p2][0])s[p1][0]=s[p2][0];
        if(s[p1][1]&&s[p2][1])mg(s[p1][1],s[p2][1],mid,r);else if(s[p2][1])s[p1][1]=s[p2][1];
        v[p1]=max(v[s[p1][0]],v[s[p1][1]]);
    }
}lt;
inline void dfs1(int u)//处理lca 
{
    for(int i=0;fa[u][i];i++)fa[u][i+1]=fa[fa[u][i]][i];dep[u]=dep[fa[u][0]]+1;
    for(int i=al[u];i;i=x[i])if(v[i]!=fa[u][0])fa[v[i]][0]=u,dfs1(v[i]);
}
inline int lca(int u,int v)//求lca 
{
    if(dep[u]<dep[v])swap(u,v);for(int d=dep[u]-dep[v],i=0;d;d>>=1,i++)if(d&1)u=fa[u][i];
    if(u==v)return u;for(int i=18;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
inline void dfs2(int u)//线段树合并 
{
    for(int i=al[u];i;i=x[i])if(v[i]!=fa[u][0])dfs2(v[i]),lt.mg(u,v[i],0,1e5);
    vector <data> :: iterator it;
    for(it=ve[u].begin();it!=ve[u].end();++it){lt.ins(u,0,1e5,*it);}
    ans[u]=lt.v[u].u;
}
int main()
{
    scanf("%d%d",&n,&m);lt.ih();
    for(int i=1,u,v;i<n;i++){scanf("%d%d",&u,&v);add(u,v),add(v,u);}dfs1(1);
    for(int i=1,u,v,va;i<=m;i++)//拆成4个操作 
    {
        scanf("%d%d%d",&u,&v,&va);int lc=lca(u,v);
        ve[u].push_back((data){va,1});ve[v].push_back((data){va,1});
        ve[lc].push_back((data){va,-1});ve[fa[lc][0]].push_back((data){va,-1});
    }dfs2(1);for(int i=1;i<=n;i++)printf("%d\n",ans[i]);return 0;//拜拜程序~ 
}