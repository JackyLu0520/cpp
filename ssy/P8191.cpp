#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
inline long long sq(long long x){return x*x;}
struct node{
    long long x,y;
    node(){}
    node(long long _x,long long _y){x=_x;y=_y;}
    bool operator<(const node& a)const{
        return x<a.x;
    }
}a[N];
struct edge{
    int u,v;
    long long w;
    edge(){}
    edge(int _u,int _v){
        u=_u,v=_v;
        w=sq(a[u].x-a[v].x)+sq(a[u].y-a[v].y);
    }
    bool operator<(const edge& a)const{
        return w<a.w;
    }
}e[10*N];int tot=0;
int last[11]={0};
struct dsu{
    int fa[N];
    dsu(int n){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
long long ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].x,&a[i].y);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10;j++)
            if(last[j])
                e[++tot]=edge(i,last[j]);
        last[a[i].y]=i;
    }
    sort(e+1,e+tot+1);
    /*for(int i=1;i<=tot;i++)
        printf("%d %d %lld\n",e[i].u,e[i].v,e[i].w);
    printf("\n");*/
    dsu d(n);
    for(int i=1;i<=tot;i++)
        if(d.query(e[i].u)!=d.query(e[i].v)){
            d.merge(e[i].u,e[i].v);
            ans+=e[i].w;
        }
    printf("%lld",ans);
    return 0;
}