#include<bits/stdc++.h>
using namespace std;
constexpr int N=505;
int s,p,x[N],y[N];
struct E{
    int u,v;double w;
    E(){}
    E(int _u,int _v,double _w){
        u=_u,v=_v,w=_w;
    }
}e[N*N];
int tot=0;
double dis(int i,int j){
    return hypot(x[i]-x[j],y[i]-y[j]);
}
struct dsu{
    int fa[N],cnt;
    dsu(){for(int i=1;i<=p;i++)fa[i]=i;cnt=p;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    bool merge(int x,int y){int xx=query(x),yy=query(y);if(xx==yy)return 0;fa[xx]=yy;cnt--;return 1;}
};
double ans;
int main(){
    scanf("%d%d",&s,&p);
    for(int i=1;i<=p;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=p;i++)
        for(int j=i+1;j<=p;j++)
            e[++tot]=E(i,j,dis(i,j));
    sort(e+1,e+tot+1,[](E a,E b){return a.w<b.w;});
    dsu d;
    for(int i=1;i<=tot&&d.cnt>s;i++)
        if(d.merge(e[i].u,e[i].v))
            ans=e[i].w;
    printf("%.2lf",ans);
    return 0;
}