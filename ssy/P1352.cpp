#include<bits/stdc++.h>
using namespace std;
const int N=6e3+10;
int n,r[N],fa[N],root;
vector<int>s[N];
int dp[N][2];
void dfs(int u){
    dp[u][0]=0;dp[u][1]=r[u];
    for(int v:s[u]){
        dfs(v);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        fa[u]=v;s[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!fa[i]){
            root=i;break;
        }
    dfs(root);
    printf("%d",max(dp[root][0],dp[root][1]));
    return 0;
}