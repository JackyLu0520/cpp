#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,L=20,M=3e5+10;
int n,m;
int head[N],nxt[2*N],ver[2*N],e[2*N],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int fa[N][L],depth[N],w[N][L];
void dfs1(int u,int in_edge){
    depth[u]=depth[ver[in_edge^1]]+1;
    fa[u][0]=ver[in_edge^1];
    w[u][0]=e[in_edge];
    for(int i=1;i<L;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
        w[u][i]=w[u][i-1]+w[fa[u][i-1]][i-1];
    }
    for(int i=head[u];i;i=nxt[i])
        if(i!=(in_edge^1))
            dfs1(ver[i],i);
}
pair<int,int> lca(int u,int v){
    int ans=0;
    if(depth[u]<depth[v])   swap(u,v);
    int t=depth[u]-depth[v];
    for(int i=0;t;i++){
        if(t&1){ans+=w[u][i];u=fa[u][i];}
        t>>=1;
    }
    if(u==v)    return make_pair(u,ans);
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            ans+=w[u][i]+w[v][i];
            u=fa[u][i];
            v=fa[v][i];
        }
    return make_pair(fa[u][0],ans+w[u][0]+w[v][0]);
}
struct work{
    int u,v,lca,len;
    work(){}
    work(int _u,int _v,int _lca,int _len){
        u=_u;v=_v;lca=_lca;len=_len;
    }
}a[M];
int maxlen=0;
int s[N];
void dfs2(int u,int in_edge){
    for(int i=head[u];i;i=nxt[i])
        if(i!=(in_edge^1)){
            dfs2(ver[i],i);
            s[u]+=s[ver[i]];
        }
}
bool check(int x){
    memset(s,0,sizeof(s));
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(a[i].len>x){
            s[a[i].u]++;s[a[i].v]++;
            s[a[i].lca]-=2;cnt++;
        }
    dfs2(1,0);
    int t=0;
    for(int i=1;i<=n;i++)
        if(s[i]==cnt)
            t=max(t,w[i][0]);
    if(maxlen-t>x)  return 0;
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dfs1(1,0);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        pair<int,int>t=lca(u,v);
        a[i]=work(u,v,t.first,t.second);
        maxlen=max(maxlen,t.second);
    }
    int l=0,r=maxlen;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))  r=mid;
        else            l=mid+1;
    }
    printf("%d",l);
    return 0;
}