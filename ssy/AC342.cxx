#include<bits/stdc++.h>
using namespace std;
const int N=25010,M=150010;
int n,r,p,s;
int head[N],nxt[M],ver[M],e[M],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
deque<int>q;
int dis[N],inq[N];
int main(){
    scanf("%d%d%d%d",&n,&r,&p,&s);
    for(int i=1;i<=r;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    for(int i=1;i<=p;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    q.push_back(s);dis[s]=0;inq[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop_front();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.empty()||dis[v]>dis[q.front()]?q.push_back(v):q.push_front(v);
                    inq[v]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(dis[i]==0x3f3f3f3f)
            printf("NO PATH\n");
        else
            printf("%d\n",dis[i]);
    return 0;
}