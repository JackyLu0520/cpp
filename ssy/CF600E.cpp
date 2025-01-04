#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,c[N];
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int size[N],son[N];
void dfs1(int u,int p){
    size[u]=1;son[u]=0;
    int maxsize=0;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>maxsize)
            maxsize=size[v],son[u]=v;
    }
}
int ans[N];
void dfs2(int u,int p){

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);

}