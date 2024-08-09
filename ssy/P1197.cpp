#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10,M=2e5+10;
int n,m;
int u[M],v[M];
int k,a[N];
int b[N];
struct dsu{
    int fa[N],cnt;
    dsu(int _n){for(int i=1;i<=_n;i++)fa[i]=i;cnt=_n;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){int xx=query(x),yy=query(y);fa[xx]=yy;if(xx!=yy)cnt--;}
};
vector<int>c[N];
int ans[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
        u[i]++;v[i]++;
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);a[i]++;
        b[a[i]]=1;
    }
    dsu d(n);
    for(int i=1;i<=m;i++)
        if(!b[u[i]]&&!b[v[i]])
            d.merge(u[i],v[i]);
        else{
            if(b[u[i]])  c[u[i]].push_back(v[i]);
            if(b[v[i]])  c[v[i]].push_back(u[i]);
        }
    for(int i=k;i>=1;i--){
        ans[i]=d.cnt-i;
        for(int v:c[a[i]])
            if(!b[v])
                d.merge(a[i],v);
        b[a[i]]=0;
    }
    printf("%d\n",d.cnt);
    for(int i=1;i<=k;i++)
        printf("%d\n",ans[i]);
    return 0;
}