#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,k,s[N],dp[N];
deque<pair<int,int>>q;
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        s[i]+=s[i-1];
    }
    q.push_back(make_pair(0,0));
    for(int i=1;i<=n;i++){
        int t=dp[i-1]-s[i];
        while(!q.empty()&&q.back().second<=t)   q.pop_back();
        q.push_back(make_pair(i,t));
        while(!q.empty()&&i-q.front().first>k)   q.pop_front();
        dp[i]=q.front().second+s[i];
    }
    printf("%lld",dp[n]);
    return 0;
}