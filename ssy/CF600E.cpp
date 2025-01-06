#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,c[N];
long long head[N],nxt[2*N],ver[2*N],tot=1;
void add(long long u,long long v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
long long ans[N],mx[N];
map<long long,long long>cnt[N];
void dfs(long long u,long long p){
    cnt[u][c[u]]=1;
    ans[u]=c[u];
    mx[u]=1;
    for(long long i=head[u];i;i=nxt[i]){
        long long v=ver[i];
        if(v==p)    continue;
        dfs(v,u);
        if(cnt[u].size()<cnt[v].size()){
            cnt[u].swap(cnt[v]);
            ans[u]=ans[v];
            mx[u]=mx[v];
        }
        for(auto &i:cnt[v]){
            cnt[u][i.first]+=i.second;
            if(cnt[u][i.first]>mx[u])
                mx[u]=cnt[u][i.first],ans[u]=0;
            if(cnt[u][i.first]==mx[u])
                ans[u]+=i.first;
        }
    }
}
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&c[i]);
    for(long long i=1;i<n;i++){
        long long u,v;
        scanf("%lld%lld",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    for(long long i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}