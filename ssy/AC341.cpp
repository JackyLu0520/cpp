#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=5e5+10;
int n,m;
int head[3*N],nxt[6*M],ver[6*M],e[6*M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[3*N],inq[3*N];
queue<int>q;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int w;scanf("%d",&w);
        add(i,n+i,w);
        add(n+i,2*n+i,-w);
    }
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,0);add(n+u,n+v,0);add(2*n+u,2*n+v,0);
        if(w==2){
            add(v,u,0);add(n+v,n+u,0);add(2*n+v,2*n+u,0);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    dis[1]=0;inq[1]=1;q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
    printf("%d",-dis[3*n]);
    return 0;
}