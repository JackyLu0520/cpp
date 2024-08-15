#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int head[N],nxt[2*N],ver[2*N],e[2*N],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],fa[N],s[N],w[N];
void dfs1(int u,int in_edge){
    dis[u]=dis[ver[in_edge^1]]+e[in_edge];fa[u]=ver[in_edge^1];
    w[u]=e[in_edge];
    for(int i=head[u];i;i=nxt[i])
        if(i!=(in_edge^1))
            dfs1(ver[i],i);
}
int U=0,V=0,ans1=0,ans2=0,len=0,x=0,y=0;bool f[N]={0};
bool dfs2(int u,int in_edge){
    if(f[u])    return 0;
    dis[u]=dis[ver[in_edge^1]]+e[in_edge];
    if(dis[u]==len) return 1;
    bool f=0;
    for(int i=head[u];i;i=nxt[i])
        if(i!=(in_edge^1))
            f=f||dfs2(ver[i],i);
    return f;
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++)
        if(dis[U]<dis[i])
            U=i;
    dfs1(U,0);
    for(int i=1;i<=n;i++)
        if(ans1<dis[i]){
            ans1=dis[i];
            V=i;
        }
    for(int i=V;i!=U;i=fa[i])   s[fa[i]]=i;
    for(int i=V;i!=fa[U];i=fa[i])   f[i]=1;
    len=ans1-w[s[U]];
    for(int i=s[U];i!=V;i=s[i]){
        f[i]=0;dis[i]=0;
        if(dfs2(i,0)){
            x=i;
            break;
        }else   len-=w[s[i]];
        f[i]=1;
    }
    len=ans1-w[V];
    for(int i=fa[V];i!=U;i=fa[i]){
        f[i]=0;dis[i]=0;
        if(dfs2(i,0)){
            y=i;
            break;
        }else   len-=w[i];
        f[i]=1;
    }
    //printf("%d %d %d %d\n",U,V,x,y);
    for(int i=(x?x:V);i!=(y?y:U);i=fa[i]){
        ans2++;
        if(i==0){
            ans2=0;
            break;
        }
    }
    printf("%lld\n%lld",ans1,ans2);
    return 0;
}