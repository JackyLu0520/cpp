#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,W,dp[N];
int main(){
    scanf("%d%d",&n,&W);
    for(int i=1;i<=n;i++){
        int v,w,m;
        scanf("%d%d%d",&v,&w,&m);
        m=min(m,W/w);
        for(int x=0;x<w;x++){
            deque<pair<int,int>>q;
            for(int y=0;y<=(W-x)/w;y++){
                int t=dp[x+y*w]-y*v;
                while(!q.empty()&&q.back().second<=t)  q.pop_back();
                q.push_back(make_pair(y,t));
                while(!q.empty()&&y-q.front().first>m) q.pop_front();
                dp[x+y*w]=max(dp[x+y*w],q.front().second+y*v);
            }
        }
    }
    printf("%d",dp[W]);
    return 0;
}