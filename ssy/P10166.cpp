#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e6+10;
int n,m,a[N];
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
long long dp[N],ind[N],ans=0,x=1e9+10,y=1e9+10;
queue<int>q;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);ind[v]++;
    }
    for(int i=1;i<=n;i++)
        if(a[i]<=x)
            y=x,x=a[i];
        else if(a[i]<y)
            y=a[i];
    ans=(x+y)*2;
    for(int i=1;i<=n;i++)
        dp[i]=a[i];
    for(int i=1;i<=n;i++)
        if(!ind[i])
            q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            ind[v]--;
            ans=min(ans,a[v]+dp[u]);
            dp[v]=min(dp[u],dp[v]);
            if(!ind[v]) q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        if(ind[i]){
            ans=0;
            break;
        }
    printf("%lld",ans);
    return 0;
}