#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+10,M=2e6+10;
int n,m,x;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dfn[N],low[N],dfsid=0;
int c[N],sccid=0;
stack<int>stk;
bool instk[N];
int w[N];
void tarjan(int u){
    dfn[u]=low[u]=++dfsid;
    stk.push(u);instk[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(instk[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        sccid++;
        int t;
        do{
            t=stk.top();stk.pop();
            c[t]=sccid;
            instk[t]=0;
            w[sccid]++;
        }while(t!=u);
    }
}
int hc[N],nc[M],vc[M],tc=1;
void addc(int u,int v){
    vc[++tc]=v;nc[tc]=hc[u];hc[u]=tc;
}
queue<int>q;
int ind[N],maxw[N],cnt[N];
void toposort(){
    for(int i=1;i<=sccid;i++)
        if(!ind[i]){
            q.push(i);
            maxw[i]=w[i];
            cnt[i]=1;
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=hc[u];i;i=nc[i]){
            int v=vc[i];
            ind[v]--;
            if(maxw[v]==maxw[u]+w[v])
                cnt[v]=(cnt[v]+cnt[u])%x;
            else if(maxw[v]<maxw[u]+w[v]){
                maxw[v]=maxw[u]+w[v];
                cnt[v]=cnt[u];
            }
            if(!ind[v]) q.push(v);
        }
    }
}
int ans1,ans2;
set<pair<int,int>>st;
signed main(){
    scanf("%lld%lld%lld",&n,&m,&x);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%lld%lld",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int u=1;u<=n;u++){
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(c[u]!=c[v]&&!st.count(make_pair(c[u],c[v]))){
                addc(c[u],c[v]);
                ind[c[v]]++;
                st.emplace(c[u],c[v]);
            }
        }
    }
    toposort();
    for(int i=1;i<=sccid;i++)
        ans1=max(ans1,maxw[i]);
    for(int i=1;i<=sccid;i++)
        if(maxw[i]==ans1)
            ans2=(ans2+cnt[i])%x;
    printf("%lld\n%lld",ans1,ans2);
    return 0;
}