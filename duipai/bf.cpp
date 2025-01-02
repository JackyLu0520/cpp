#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N=100005,S=N*4*20;
int T,n,m,root[N],ls[S],rs[S],sum[S],v[N],ha[N],cnt,total;
void pushup(int rt){
    sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}
int build(int le,int ri){
    int rt=++total;
    if (le==ri){
        ls[rt]=rs[rt]=sum[rt]=0;
        return rt;
    }
    int mid=(le+ri)>>1;
    ls[rt]=build(le,mid);
    rs[rt]=build(mid+1,ri);
    pushup(rt);
    return rt;
}
int update(int rt,int le,int ri,int pos){
    int now=++total;
    if (le==ri){
        sum[now]=sum[rt]+1;
        ls[now]=rs[now]=0;
        return now;
    }
    int mid=(le+ri)>>1;
    if (pos<=mid)
        ls[now]=update(ls[rt],le,mid,pos),rs[now]=rs[rt];
    else
        rs[now]=update(rs[rt],mid+1,ri,pos),ls[now]=ls[rt];
    pushup(now);
    return now;
}
int query(int rt1,int rt2,int le,int ri,int val){
    if (ha[ri]<=val)
        return sum[rt2]-sum[rt1];
    if (ha[le]>val)
        return 0;
    int mid=(le+ri)>>1;
    return query(ls[rt1],ls[rt2],le,mid,val)+query(rs[rt1],rs[rt2],mid+1,ri,val);
}
int main(){
    scanf("%d",&T);
    for (int Case=1;Case<=T;Case++){
        printf("Case %d:\n",Case);
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]),ha[i]=v[i];
        sort(ha+1,ha+n+1);
        cnt=1;
        for (int i=2;i<=n;i++)
            if (ha[i]!=ha[i-1])
                ha[++cnt]=ha[i];
        total=0;
        root[0]=build(1,cnt);
        for (int i=1;i<=n;i++){
            v[i]=lower_bound(ha+1,ha+cnt+1,v[i])-ha;
            root[i]=update(root[i-1],1,cnt,v[i]);
        }
        for (int i=1;i<=m;i++){
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            printf("%d\n",query(root[a],root[b+1],1,cnt,v));
        }
    }
    return 0;
}