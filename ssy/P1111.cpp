#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e5+10;
int n,m,cnt;
struct T{
    int x,y,t;
    T(){}
    T(int X,int Y,int T){x=X;y=Y;t=T;}
    bool operator < (const T& a) const{return t<a.t;}
}a[M];
struct dsu{
    int n,fa[N];
    dsu(int _n){n=_n;for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    bool merge(int x,int y){int xx=query(x),yy=query(y);if(xx==yy)return 0;fa[xx]=yy;return 1;}
};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        a[i]=T(x,y,t);
    }
    sort(a+1,a+m+1);
    cnt=n;
    dsu d(n);
    for(int i=1;i<=m;i++){
        cnt-=d.merge(a[i].x,a[i].y);
        if(cnt==1){
            printf("%d",a[i].t);
            return 0;
        }
    }
    printf("-1");
    return 0;
}