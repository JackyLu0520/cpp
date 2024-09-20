#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e4+10;
int n,m;
int head[N],nxt[M],ver[M],e[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int spfa(int s,int t){
    int dis[N],inq[N],cnt[N];
    queue<int>q;
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    dis[s]=0;inq[s]=1;q.push(s);cnt[s]=1;
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
                    if(cnt[v]>n)
                        return -1;
                }
            }
        }
    }
    return dis[t];
}
int ans1,ans2;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,-w);
    }
    ans1=spfa(1,n);
    ans2=spfa(n,1);
    if(ans1==-1||ans2==-1)  printf("Forever love");
    else                    printf("%d",min(ans1,ans2));
    return 0;
}