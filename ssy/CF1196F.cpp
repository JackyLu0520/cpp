#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e5+10,K=410;
int n,m,k;
struct E{
    int u,v;long long w;
    inline bool operator<(const E& a)const{
        return w<a.w;
    }
}e[M];
vector<int>t;
vector<long long>t1;
long long dis[2*K][2*K];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+m+1);
    for(int i=1;i<=k;i++){
        t.emplace_back(e[i].u);
        t.emplace_back(e[i].v);
    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    for(int i=1;i<=t.size();i++)
        for(int j=1;j<=t.size();j++)
            if(i==j)    dis[i][j]=0;
            else        dis[i][j]=0x3f3f3f3f3f3f3f3fll;
    for(int i=1;i<=k;i++){
        int uu=lower_bound(t.begin(),t.end(),e[i].u)-t.begin()+1;
        int vv=lower_bound(t.begin(),t.end(),e[i].v)-t.begin()+1;
        dis[uu][vv]=e[i].w;
        dis[vv][uu]=e[i].w;
    }
    for(int k=1;k<=t.size();k++)
        for(int i=1;i<=t.size();i++)
            for(int j=1;j<=t.size();j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=t.size();i++)
        for(int j=i+1;j<=t.size();j++)
            t1.push_back(dis[i][j]);
    sort(t1.begin(),t1.end());
    printf("%lld",t1[k-1]);
    return 0;
}