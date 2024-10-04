#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int b[N],dp[N];
void dfs(int u,int p){
    int cnt=0;
    for(int i=head[u];i;i=nxt[i])
        if(!b[ver[i]]&&ver[i]!=p)
            cnt++;
    if(cnt==0&&b[u]){
        dp[u]=0;return;
    }
    if(cnt==1&&b[u]){
        b[u]--;
        for(int i=head[u];i;i=nxt[i])
            if(ver[i]!=p&&!b[ver[i]])
                b[ver[i]]++;
    }
    dp[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v==p)    continue;
        dfs(v,u);
        dp[u]+=dp[v];
    }
}
int main(){
    freopen("swaying.in","r",stdin);
    freopen("swaying.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    for(int i=1;i<=k;i++){
        int k;scanf("%d",&k);
        b[k]=1;
    }
    dfs(1,0);
    printf("%d\n",dp[1]);
    /*for(int i=1;i<=n;i++)
        printf("%d ",dp[i]);
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%d:",i);
        for(int j=head[i];j;j=nxt[j])
            printf("%d ",ver[j]);
        printf("\n");
    }*/
    return 0;
}