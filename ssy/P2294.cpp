#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=1.5e4+10;
int n,m;
int head[N],nxt[M],ver[M],e[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
void clear(){
    memset(head,0,sizeof(head));tot=1;
}
int spfa(int s){
    int dis[N],inq[N],cnt[N];
    queue<int>q;
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    q.push(s);dis[s]=0;inq[s]=1;cnt[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
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
    int t;scanf("%d",&t);
    while(t--){
        clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u-1,v,w);add(v,u-1,-w);
        }
        for(int i=1;i<=n;i++)
            add(n+1,i,0);
        printf(spfa(n+1)?"true\n":"false\n");
    }
    return 0;
}