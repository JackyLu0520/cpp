#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=5e3+10;
const double eps=1e-4;
int n,m,u[M],v[M],w[M],f[N];
int head[N],nxt[M],ver[M],tot=1;
double e[M];
void clear(){
    memset(head,0,sizeof(head));
    tot=1;
}
void add(int u,int v,double w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
bool spfa(){
    double dis[N];
    int inq[N],cnt[N];
    queue<int>q;
    for(int i=1;i<=n;i++)
        dis[i]=1e9;
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    dis[1]=0;inq[1]=1;q.push(1);cnt[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            double w=e[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v]>n)
                        return 1;
                }
            }
        }
    }
    return 0;
}
bool check(double x){
    clear();
    for(int i=1;i<=m;i++)
        add(u[i],v[i],x*w[i]-f[u[i]]);
    return spfa();
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    double l=0,r=0;
    for(int i=1;i<=n;i++)
        r+=f[i];
    while(r-l>=eps){
        double mid=(l+r)/2;
        if(check(mid))  l=mid;
        else            r=mid;
    }
    printf("%.2lf",l);
    return 0;
}