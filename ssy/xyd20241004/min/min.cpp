#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+10;
int n,m,k;
vector<int>a[N],ans;
vector<int>solve(vector<int>&a,vector<int>&b){
    if(a.empty()||b.empty())    return vector<int>();
    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;
    vector<int>res;
    for(int i=0;i<a.size();i++)
        q.push(make_pair(a[i]+b[0],make_pair(i,0)));
    while(!q.empty()&&res.size()<k){
        auto tmp=q.top();q.pop();
        res.push_back(tmp.first);
        if(tmp.second.second+1<b.size())
            q.push(
                make_pair(
                    a[tmp.second.first]+b[tmp.second.second+1],
                    make_pair(
                        tmp.second.first,
                        tmp.second.second+1)));
    }
    return res;
}
signed main(){
    freopen("min.in","r",stdin);
    freopen("min.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++){
        int c,w;scanf("%lld%lld",&c,&w);
        a[c].push_back(w);
    }
    for(int i=1;i<=m;i++)
        sort(a[i].begin(),a[i].end());
    ans.push_back(0);
    for(int i=1;i<=m;i++)
        ans=solve(ans,a[i]);
    for(int i=0;i<ans.size();i++)
        printf("%lld\n",ans[i]);
    for(int i=ans.size();i<k;i++)
        printf("-1\n");
    return 0;
}