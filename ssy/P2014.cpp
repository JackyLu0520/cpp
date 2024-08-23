#include<bits/stdc++.h>
using namespace std;
const int N=310,M=310;
int n,m;
vector<int>s[N];
int dp[N][M];
void dfs(int u){
    for(int v:s[u]){
        dfs(v);
        for(int j=m;j>0;j--)
            for(int k=0;k<j;k++)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d%d",&k,&dp[i][1]);
        s[k].push_back(i);
    }
    m++;
    dfs(0);
    printf("%d",dp[0][m]);
    return 0;
}