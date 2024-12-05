#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
int n;
struct P{
    int x,y;
}p[N];
struct dsu{
    int fa[N],cnt;
    dsu(int n){
        cnt=n;
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int query(int x){
        return fa[x]==x?x:fa[x]=query(fa[x]);
    }
    void merge(int x,int y){
        int xx=query(x),yy=query(y);
        if(xx==yy)  return;
        fa[xx]=yy;cnt--;
    }
};
bool check2(int x,dsu d){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(d.query(i)==d.query(j))
                continue;
            if(p[i].x==p[j].x&&abs(p[i].y-p[j].y)<=2*x)
                return 1;
            if(p[i].y==p[j].y&&abs(p[i].x-p[j].x)<=2*x)
                return 1;
            if(abs(p[i].x-p[j].x)<=x&&abs(p[i].y-p[j].y)<=x)
                return 1;
        }
    return 0;
}
bool check3(int x,dsu d){
    vector<pair<int,int>>xseg,yseg;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(p[i].x==p[j].x&&d.query(i)!=d.query(j))
                xseg.emplace_back(i,j);
            if(p[i].y==p[j].y&&d.query(i)!=d.query(j))
                yseg.emplace_back(i,j);
        }
    for(int i=1;i<=n;i++)
        for(pair<int,int>&t:xseg){
            int j,k;tie(j,k)=t;
            if(d.query(i)==d.query(j)||d.query(i)==d.query(k))
                continue;
            P o;o.x=p[j].x,o.y=p[i].y;
            if(abs(p[i].x-o.x)<=x&&abs(p[j].y-o.y)<=x&&abs(p[k].y-o.y)<=x)
                return 1;
        }
    for(int i=1;i<=n;i++)
        for(pair<int,int>&t:yseg){
            int j,k;tie(j,k)=t;
            if(d.query(i)==d.query(j)||d.query(i)==d.query(k))
                continue;
            P o;o.y=p[j].y,o.x=p[i].x;
            if(abs(p[i].y-o.y)<=x&&abs(p[j].x-o.x)<=x&&abs(p[k].x-o.x)<=x)
                return 1;
        }
    return 0;
}
bool check4(int x,dsu d){
    vector<pair<int,int>>xseg,yseg;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(p[i].x==p[j].x&&d.query(i)!=d.query(j))
                xseg.emplace_back(i,j);
            if(p[i].y==p[j].y&&d.query(i)!=d.query(j))
                yseg.emplace_back(i,j);
        }
    for(pair<int,int>&tx:xseg)
        for(pair<int,int>&ty:yseg){
            int px,qx,py,qy;
            tie(px,qx)=tx;tie(py,qy)=ty;
            if(d.query(px)==d.query(py)||d.query(qx)==d.query(qy)||
                d.query(px)==d.query(qy)||d.query(qx)==d.query(py))
                continue;
            P o;o.x=p[px].x;o.y=p[py].y;
            if(abs(o.x-p[py].x)<=x&&abs(o.x-p[qy].x)<=x&&
                abs(o.y-p[px].y)<=x&&abs(o.y-p[qx].y)<=x)
                return 1;
        }
    return 0;
}
bool check(int x){
    dsu d(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((p[i].x==p[j].x&&abs(p[i].y-p[j].y)<=x)||
                (p[i].y==p[j].y&&abs(p[i].x-p[j].x)<=x))
                d.merge(i,j);
    if(d.cnt==1)
        return 1;
    else if(d.cnt==2)
        return check2(x,d);
    else if(d.cnt==3)
        return check3(x,d);
    else if(d.cnt==4)
        return check4(x,d);
    else
        return 0;
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].y);
    int l=0,r=2e9+10;
    if(!check(r+1)){
        printf("-1");
        return 0;
    }
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))  r=mid;
        else            l=mid+1;
    }
    printf("%lld",l);
    return 0;
}