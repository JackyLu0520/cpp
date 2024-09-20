#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10,M=6e3+10;
int n,m;
int head[N],nxt[M],ver[M],e[M],tot=1;
void clear(){
    memset(head,0,sizeof(head));
    tot=1;
}
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
bool spfa(){
    bool inq[N];
    int dis[N],cnt[N];
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    queue<int>q;
    q.push(1);dis[1]=0;inq[1]=1;cnt[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.push(v);
                    cnt[v]++;
                    inq[v]=1;
                    if(cnt[v]>=n)
                        return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        clear();
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w>=0)add(u,v,w),add(v,u,w);
            else    add(u,v,w);
        }
        printf(spfa()?"NO\n":"YES\n");
    }
    return 0;
}