#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct P{
    int id,x,y,z;
    P(){}
    P(int _id,int _x,int _y,int _z){
        id=_id,x=_x,y=_y,z=_z;
    }
}p[N];
struct E{
    int u,v,w;
    E(){}
    E(int _u,int _v,int _w){
        u=_u,v=_v,w=_w;
    }
}e[3*N];
int dis(int i,int j){
    return min(abs(p[i].x-p[j].x),min(abs(p[i].y-p[j].y),abs(p[i].z-p[j].z)));
}
int tot=0;
struct dsu{
    int fa[N],cnt;
    dsu(){for(int i=1;i<=n;i++) fa[i]=i;cnt=n;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    bool merge(int x,int y){int xx=query(x),yy=query(y);if(xx==yy)return 0;fa[xx]=yy;cnt--;return 1;}
};
int ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        p[i]=P(i,x,y,z);
    }
    sort(p+1,p+n+1,[](P a,P b){return a.x<b.x;});
    for(int i=1;i<n;i++)    e[++tot]=E(p[i].id,p[i+1].id,dis(i,i+1));
    sort(p+1,p+n+1,[](P a,P b){return a.y<b.y;});
    for(int i=1;i<n;i++)    e[++tot]=E(p[i].id,p[i+1].id,dis(i,i+1));
    sort(p+1,p+n+1,[](P a,P b){return a.z<b.z;});
    for(int i=1;i<n;i++)    e[++tot]=E(p[i].id,p[i+1].id,dis(i,i+1));
    sort(e+1,e+tot+1,[](E a,E b){return a.w<b.w;});
    dsu d;
    for(int i=1;i<=tot&&d.cnt>1;i++)
        if(d.merge(e[i].u,e[i].v))
            ans+=e[i].w;
    printf("%d",ans);
    return 0;
}