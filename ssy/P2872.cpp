#include<bits/stdc++.h>
using namespace std;
constexpr int N=1010,M=1010;
int n,m;
int x[N],y[N];
pair<double,pair<int,int>>e[N*N];
int tot=0;
double dis(int u,int v){
    return hypot((long long)x[u]-x[v],(long long)y[u]-y[v]);
}
double ans;
struct dsu{
    int fa[N],cnt;
    dsu(){for(int i=1;i<=n;i++) fa[i]=i;cnt=n;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    bool merge(int x,int y){int xx=query(x),yy=query(y);if(xx==yy)return 0;fa[xx]=yy;cnt--;return 1;}
};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            e[++tot]=make_pair(dis(i,j),make_pair(i,j));
    dsu d;
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        d.merge(u,v);
    }
    sort(e+1,e+tot+1);
    for(int i=1;i<=n*(n-1)/2&&d.cnt>1;i++){
        if(d.merge(e[i].second.first,e[i].second.second)){
            ans+=e[i].first;
        }
    }
    printf("%.2lf",ans);
    return 0;
}