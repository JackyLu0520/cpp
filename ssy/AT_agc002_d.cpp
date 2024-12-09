#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5+10,L=23;
int n,m,q;
struct E{
    int u,v,id;
    inline bool operator<(const E& a)const{
        return id<a.id;
    }
}e[M];
struct mod_dsu{
    int fa[2*N],tot=0;
    int newnode(){tot++;fa[tot]=tot;return tot;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    int merge(int x,int y){
        int xx=query(x),yy=query(y);
        if(xx==yy)  return xx;
        return fa[xx]=fa[yy]=newnode();
    }
}d;
int fa[2*N][L],vw[2*N],sz[2*N];
void kruskal(){
    for(int i=1;i<=n;i++){
        d.newnode();
        sz[i]=1;
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int uu=d.query(e[i].u),vv=d.query(e[i].v);
        if(uu==vv)  continue;
        int f=d.merge(uu,vv);
        fa[uu][0]=f;fa[vv][0]=f;
        vw[f]=e[i].id;
        sz[f]=sz[uu]+sz[vv];
    }
}
int solve(int u,int lim){
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]&&vw[fa[u][i]]<=lim)
            u=fa[u][i];
    return u;
}
bool check(int x,int y,int z,int lim){
    int xx=solve(x,lim),yy=solve(y,lim);
    if(xx==yy)  return sz[xx]>=z;
    else        return sz[xx]+sz[yy]>=z;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&e[i].u,&e[i].v);
        e[i].id=i;
    }
    kruskal();
    for(int i=2*n;i>=1;i--)
        for(int j=1;j<L;j++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    scanf("%d",&q);
    while(q--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int l=1,r=m;
        while(l<r){
            int mid=(l+r)/2;
            if(check(x,y,z,mid))    r=mid;
            else                    l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}