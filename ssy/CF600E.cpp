#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,c[N];
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ans[N],mx[N];
map<int,int>cnt[N];
void dfs(int u,int p){
    cnt[u][c[u]]=1;
    ans[u]=c[u];
    mx[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}