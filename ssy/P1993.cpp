#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=1.5e4+10;
int n,m,s=0;
int head[N],nxt[M],ver[M],e[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int dis[N],inq[N],cnt[N];
queue<int>q;
bool spfa(){
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    q.push(s);dis[s]=0;inq[s]=1;cnt[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=1;
                    cnt[v]++;
                    if(cnt[v]>n)  return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int t,u,v,w;scanf("%d%d%d",&t,&u,&v);
        if(t==1){scanf("%d",&w);add(u,v,-w);}
        if(t==2){scanf("%d",&w);add(v,u,w);}
        if(t==3){add(u,v,0);add(v,u,0);}
    }
    for(int i=1;i<=n;i++)
        add(0,i,0);
    printf(spfa()?"Yes":"No");
    return 0;
}