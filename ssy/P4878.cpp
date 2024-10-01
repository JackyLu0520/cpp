#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=1.5e4+10;
int n,m1,m2;
int head[N],nxt[M],ver[M],e[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
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
        for(int i=head[u];i!=-1;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=1;
                    cnt[v]++;
                    if(cnt[v]>n)  return -1;
                }
            }
        }
    }
    return dis[n]==0x3f3f3f3f?-2:dis[n];
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    for(int i=1;i<=m2;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(v,u,-w);
    }
    for(int i=1;i<=n;i++)
        add(0,i,0);
    for(int i=1;i<n;i++)
        add(i+1,i,0);
    int t=spfa(0);
    printf("%d",t<0?t:spfa(1));
    return 0;
}