#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,w,a[N];
int ind[N],outd[N],dp[N];
queue<int>q;
int ans=0;
int main(){
    freopen("bright.in","r",stdin);
    freopen("bright.out","w",stdout);
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=-min(i,w);j<=min(w,n-i);j++)
            if(j!=0&&a[i]<a[i+j]){
                ind[i+j]++;outd[i]++;
            }
    for(int i=1;i<=n;i++)
        if(!ind[i]){
            dp[i]=0;q.push(i);
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        //printf("%d ",u);
        for(int v=-min(u,w);v<=min(w,n-u);v++)
            if(v!=0&&a[u]<a[u+v]){
                ind[u+v]--;
                dp[u+v]=max(dp[u+v],dp[u]+1);
                if(!ind[u+v])   q.push(u+v);
            }
    }
    //printf("\n");
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}