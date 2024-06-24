//死机了。。。
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e5+10;
int n,m;

int head[N],nxt[M],ver[M],e[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}

int dis[N],inq[N],pre[N];
queue<int> q;
void spfa(){
    memset(inq,0,sizeof(inq));
    memset(dis,0x3f,sizeof(dis));
    q.push(1);dis[1]=0;inq[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=0;
        for(int i=head[u];i;i++){
            int v=ver[i],w=e[i];
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pre[v]=u;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
void printpath(int dest){
    if(dest==1){printf("1 ");return;}
    printpath(pre[dest]);
    printf("%d ",dest);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    spfa();
    printf("%d\n",dis[n]);
    printpath(n);
    return 0;
}