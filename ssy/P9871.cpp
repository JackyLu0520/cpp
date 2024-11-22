#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
//segtree
struct node{
    int l,r;
    long long tag;
    long long max;
}t[16*M];
void pushup(int p){
    t[p].max=max(t[2*p].max,t[2*p+1].max);
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;t[p].tag=0;
    if(l==r){t[p].max=0;return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    pushup(p);
}
void pushdown(int p){
    if(t[p].tag){
        t[2*p].tag+=t[p].tag;
        t[2*p+1].tag+=t[p].tag;
        t[2*p].max+=t[p].tag;
        t[2*p+1].max+=t[p].tag;
        t[p].tag=0;
    }
}
void add(int p,int l,int r,long long k){
    if(t[p].l>=l&&t[p].r<=r){
        t[p].tag+=k;
        t[p].max+=k;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid)  add(2*p,l,r,k);
    if(r>mid)   add(2*p+1,l,r,k);
    pushup(p);
}
long long query(int p,int l,int r){
    if(t[p].l>=l&&t[p].r<=r)
        return t[p].max;
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    long long ans=-0x3f3f3f3f3f3f3f3f;
    if(l<=mid)  ans=max(ans,query(2*p,l,r));
    if(r>mid)   ans=max(ans,query(2*p+1,l,r));
    return ans;
}
//
long long n,m,k,d;
long long x[M],y[M],v[M];
vector<long long>tmp;
long long f[2*M],g[2*M];
vector<pair<long long,long long>>yx[2*M];//x->{y,v}
inline int get(long long x){//get position of x from tmp
    return lower_bound(tmp.begin(),tmp.end(),x)-tmp.begin()+1;
}
void print(int p,int depth,bool lr){
    for(int i=1;i<=depth;i++)
        printf(" ");
    printf("%c:[%d,%d],tag=%d,max=%d\n",lr?'l':'r',t[p].l,t[p].r,t[p].tag,t[p].max);
    if(t[p].l==t[p].r)  return;
    print(2*p,depth+1,1);
    print(2*p+1,depth+1,0);
}
void init(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
    tmp.clear();
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    //discrete
    for(int i=1;i<=m;i++){
        tmp.push_back(x[i]);
        tmp.push_back(x[i]-y[i]);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    //
    for(int i=1;i<=tmp.size();i++)
        yx[i].clear();
    for(int i=1;i<=m;i++)
        yx[get(x[i])].emplace_back(get(x[i]-y[i]),v[i]);
    build(1,0,tmp.size());
#ifdef DEBUG
    print(1,0,0);
#endif
}
void solve(){
    for(int i=1;i<=tmp.size();i++){
        add(1,0,i-1,-d);
        for(auto &j:yx[i])
            add(1,0,j.first,j.second);
        add(1,i,i,g[i-1]);
        f[i]=query(1,get(tmp[i-1]-k),i-1);
        g[i]=max(g[i-1],f[i]);
    }
    printf("%lld\n",g[tmp.size()]);
}
int main(){
    int _;
    scanf("%*d%d",&_);
    while(_--){
        init();
        solve();
    }
    return 0;
}