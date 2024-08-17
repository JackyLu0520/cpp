#include<bits/stdc++.h>
using namespace std;
const int X=3e6+10;
int n,maxx=0;
vector<int> f[X];
int dp[X];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;scanf("%d%d",&x,&y);
        f[y].push_back(x);maxx=max(maxx,y);
    }
    for(int i=0;i<=maxx;i++){
        dp[i]=dp[i-1];
        for(int j:f[i])
            dp[i]=max(dp[i],dp[j-1]+i-j+1);
    }
    printf("%d",dp[maxx]);
    return 0;
}