#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,now,ans=0;
bool f[(1<<20)-1][20];
void dfs(int step){
    if(step>n){
        ans=(ans+1)%MOD;
        return;
    }
    int x=3;
    for(int i=2;i<=n;i++,x=(x<<1)|1)
        for(int j=0;j<=n-i;j++)
            if(!f[now^(x<<j)][step]){
                now^=(x<<j);
                f[now][step]=1;
                dfs(step+1);
                now^=(x<<j);
            }
}
int main(){
    scanf("%d",&n);
    dfs(1);
    printf("%d",ans);
    return 0;
}