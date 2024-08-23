#include<bits/stdc++.h>
using namespace std;
const int N=16010;
int n,a[N];
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dp[N];
void dfs(int u,int p){
    dp[u]=a[u];
    for(int i=head[u];i;i=nxt[i])
        if(ver[i]!=p){
            dfs(ver[i],u);
            if(dp[ver[i]]>0)    dp[u]+=dp[ver[i]]; 
        }
}
int ans=-0x3f3f3f3f;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}