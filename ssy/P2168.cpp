#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
typedef pair<long long,long long> pll;
priority_queue<pll,vector<pll>,greater<pll>> q;
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        long long w;
        scanf("%lld",&w);
        q.push(make_pair(w,1));
    }
    while((q.size()-1)%(k-1))   q.push(make_pair(0,1));
    while(q.size()>1){
        long long w=0,h=0;
        for(int i=1;i<=k;i++){
            pll t;
            t=q.top();q.pop();
            h=max(h,t.second);
            w+=t.first;
        }
        ans+=w;
        q.push(make_pair(w,h+1));
    }
    printf("%lld\n%lld",ans,q.top().second-1);
    return 0;
}