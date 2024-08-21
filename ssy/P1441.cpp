#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n,m,a[N],ans=0;
void solve(int b){
    bool dp[2010]={1};int tot=0,cnt=0;
    for(int i=0;i<n;i++)
        if(!(b&(1<<i))){
            for(int j=tot;j>=0;j--)
                if(dp[j]&&!dp[j+a[i]])
                    dp[j+a[i]]=1,cnt++;
            tot+=a[i];
        }
    ans=max(ans,cnt);
}
void dfs(int step,int b){
    if(step>=n){
        if(__builtin_popcount(b)==m)
            solve(b);
        return;
    }
    if(__builtin_popcount(b)<m)
        dfs(step+1,b|(1<<step));
    dfs(step+1,b);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    dfs(0,0);
    printf("%d",ans);
    return 0;
}