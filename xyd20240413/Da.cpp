#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int headr[N],nxtr[M],verr[M],totr=1;
void addr(int u,int v){
    verr[++totr]=v;nxtr[totr]=headr[u];headr[u]=totr;
}

//Kosaraju
bool vis[N];
vector<int> s;
void dfs1(int u){
    vis[u]=1;
    for(int i=head[u];i;i=nxt[i])
        if(!vis[ver[i]])
            dfs1(ver[i]);
    s.push_back(u);
}
int c[N],sccid;
void dfs2(int u){
    c[u]=sccid;
    for(int i=headr[u];i;i=nxtr[i])
        if(!c[verr[i]])
            dfs2(verr[i]);
}
void kosaraju(){
    sccid=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs1(i);
    for(int i=n-1;i>=0;i--)
        if(!c[s[i]]){
            sccid++;
            dfs2(s[i]);
        }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        addr(v,u);
    }
    kosaraju();
    printf("%d\n",sccid);
    for(int i=1;i<=n;i++)
        printf("%d ",c[i]);
    return 0;
}