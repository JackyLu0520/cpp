#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e3+10,M=4e4+10,INF=0x3f3f3f3f;
int n,m;
int head[N],nxt[M],from[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;from[tot]=u;nxt[tot]=head[u];head[u]=tot;
}
int dis[N][N],ind[N],ans[M];
int k=0,Max=-INF;
vector<int>res;
queue<int>q;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);ind[v]++;
    }
    memset(dis,~0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=n;i++)
        if(!ind[i])
            q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            ind[v]--;
            for(int i=1;i<=n;i++)
                dis[i][v]=max(dis[i][v],dis[i][u]+1);
            if(!ind[v]) q.push(v);
        }
    }
    for(int i=2;i<=tot;i++)
        ans[1]=max(ans[1],dis[ver[i]][from[i]]+1);
    for(int i=2;i<=tot;i++)
        ans[i]=max(ans[1],dis[from[i]][ver[i]]+1);
    for(int i=1;i<=tot;i++)
        Max=max(Max,ans[i]);
    for(int i=2;i<=tot;i++)
        if(Max==ans[i]){
            k++;res.push_back(i-1);
        }
    printf("%d\n%d\n",Max,k);
    for(auto it=res.begin();it!=res.end();it++)
        printf("%d ",*it);
    return 0;
}