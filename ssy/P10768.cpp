#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
pair<long long,int> a[N];
struct edge{
    int i,j;
    long long dis;
    edge(int _i,int _j){i=_i;j=_j;dis=a[i].first*a[j].first;}
};
inline bool operator<(const edge& a,const edge&b){
    return a.dis==b.dis?a.i<b.i:a.dis>b.dis;
}
priority_queue<edge>q;
struct dsu{
    int fa[N];
    dsu(){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
long long ans1=0;
vector<pair<int,int>>ans2,ans3;
int main(){
    scanf("%d%d",&n,&m);
    if(n==1){printf("0");return 0;}
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q.emplace(a[i].first>=0?1:n,i);
    }
    dsu d;
    while(!q.empty()){
        edge u=q.top();q.pop();
        int t=u.i+(a[u.j].first>=0?1:-1);
        if(t>=1&&t<=n)  q.emplace(t,u.j);
        if(a[u.i].second>=a[u.j].second)    continue;
        #ifdef DEBUG
        printf("%d %d %d\n",u.i,u.j,u.dis);
        #endif
        #ifndef DEBUG
        if(ans2.size()+ans3.size()>=m)  break;
        if(d.query(u.i)!=d.query(u.j)&&ans2.size()<n-1){
            d.merge(u.i,u.j);
            ans1+=u.dis;
            ans2.emplace_back(a[u.i].second,a[u.j].second);
        }else if(ans3.size()<m-n+1){
            ans1+=u.dis;
            ans3.emplace_back(a[u.i].second,a[u.j].second);
        }
        #endif
    }
    printf("%lld\n",ans1);
    for(pair<int,int>t:ans2){
        printf("%d %d\n",t.first,t.second);
    }
    for(pair<int,int>t:ans3){
        printf("%d %d\n",t.first,t.second);
    }
    return 0;
}