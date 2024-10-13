#include<bits/stdc++.h>
using namespace std;
constexpr int N=405,M=10010;
constexpr double eps=1e-6;
int n,m,f;
int u[M],v[M],c[M],t[M];
struct E{
    int u,v;double w;
    E(){}
    E(int _u,int _v,double _w){u=_u,v=_v,w=_w;}
    bool operator < (const E& a) const{
        return w<a.w;
    }
}e[M];
struct dsu{
    int fa[N],cnt;
    dsu(){for(int i=1;i<=n;i++)fa[i]=i;cnt=n;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    bool merge(int x,int y){int xx=query(x),yy=query(y);if(xx==yy)return 0;fa[xx]=yy;cnt--;return 1;}
};
bool check(double x){
    for(int i=1;i<=m;i++)
        e[i]=E(u[i],v[i],c[i]+x*t[i]);
    sort(e+1,e+m+1);
    dsu d;
    double ans=0;
    for(int i=1;i<=m&&d.cnt>1;i++)
        if(d.merge(e[i].u,e[i].v))
            ans+=e[i].w;
    return ans<(double)f;
}
int main(){
    scanf("%d%d%d",&n,&m,&f);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d%d",&u[i],&v[i],&c[i],&t[i]);
    double l=0,r=1e14;
    while(r-l>=eps){
        double mid=(l+r)/2;
        if(check(mid))  l=mid;
        else            r=mid;
    }
    printf("%.4lf",l);
    return 0;
}