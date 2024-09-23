#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m,s;
int head[N],nxt[M],ver[M],e[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],inq[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void spfa(){
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    q.push(make_pair(0,s));dis[s]=0;inq[s]=1;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.push(make_pair(dis[v],v));
                    inq[v]=1;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    spfa();
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
}