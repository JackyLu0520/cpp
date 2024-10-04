#include<bits/stdc++.h>
using namespace std;
constexpr int K=2e5+10;
int n,k;
vector<int>p[K];
vector<pair<int,int>>pos;
vector<int>ans;
void dfs(int now){
    if(now>k){
        vector<pair<int,int>>p1;
        for(int i=0;i<k;i++)    p1.push_back(pos[i]);
        sort(p1.begin(),p1.end());
        bool f=1;
        for(int i=0;i<k;i++){
            if(ans[i]>p1[i].second){f=0;break;}
            if(ans[i]<p1[i].second){f=1;break;}
        }
        if(!f){
            for(int i=0;i<k;i++)
                ans[i]=p1[i].second;
        }
        return;
    }
    for(int i=0;i<p[now].size();i++){
        pos.push_back(make_pair(p[now][i],now));
        dfs(now+1);
        pos.pop_back();
    }
    return;
}
int main(){
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        p[x].push_back(i);
    }
    for(int i=k;i>=1;i--)
        ans.push_back(i);
    dfs(1);
    for(int i=0;i<k;i++)
        printf("%d ",ans[i]);
    return 0;
}