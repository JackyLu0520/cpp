#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
char s[N];
int n,p=0;
int son[N][2];
int dp1[N][3],dp2[N][3];
void dfs1(){
    int cnt=s[++p]-'0';int u=p;
    if(cnt>0){
        son[u][0]=p+1;dfs1();
    }
    if(cnt>1){
        son[u][1]=p+1;dfs1();
    }
}
void dfs2(int u){
    if(!son[u][0]&&!son[u][1])  dp1[u][0]=1,dp2[u][0]=1;
    if(son[u][0]&&!son[u][1]){
        int v=son[u][0];dfs2(v);
        dp1[u][0]=max(dp1[v][1],dp1[v][2])+1;
        dp1[u][1]=max(dp1[v][0],dp1[v][2]);
        dp1[u][2]=max(dp1[v][0],dp1[v][1]);
        dp2[u][0]=min(dp2[v][1],dp2[v][2])+1;
        dp2[u][1]=min(dp2[v][0],dp2[v][2]);
        dp2[u][2]=min(dp2[v][0],dp2[v][1]);
    }
    if(son[u][1]){
        int v=son[u][0],w=son[u][1];dfs2(v);dfs2(w);
        dp1[u][0]=max(dp1[v][1]+dp1[w][2],dp1[v][2]+dp1[w][1])+1;
        dp1[u][1]=max(dp1[v][0]+dp1[w][2],dp1[v][2]+dp1[w][0]);
        dp1[u][2]=max(dp1[v][0]+dp1[w][1],dp1[v][1]+dp1[w][0]);
        dp2[u][0]=min(dp2[v][1]+dp2[w][2],dp2[v][2]+dp2[w][1])+1;
        dp2[u][1]=min(dp2[v][0]+dp2[w][2],dp2[v][2]+dp2[w][0]);
        dp2[u][2]=min(dp2[v][0]+dp2[w][1],dp2[v][1]+dp2[w][0]);
    }
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    dfs1();
    dfs2(1);
    printf("%d %d",max(dp1[1][0],max(dp1[1][1],dp1[1][2])),min(dp2[1][0],min(dp2[1][1],dp2[1][2])));
    return 0;
}