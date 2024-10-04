#include<bits/stdc++.h>
using namespace std;
constexpr int K=2e5+10;
int n,k;
vector<int>p[K];
vector<int>pos,res;
int main(){
    freopen("data.in","r",stdin);
    freopen("sol.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        p[x].push_back(i);
    }
    res.push_back(0);pos.push_back(0);
    for(int i=1;i<=k;i++){
        auto it=upper_bound(pos.begin(),pos.end(),*(p[i].end()-1))-1;
        auto it1=lower_bound(p[i].begin(),p[i].end(),*it);
        auto it2=lower_bound(pos.begin(),pos.end(),*it1);
        res.insert(it2-pos.begin()+res.begin(),i);
        pos.insert(it2,*it1);
    }
    /*for(auto it=pos.begin()+1;it!=pos.end();it++)
        printf("%d ",*it);
    printf("\n");*/
    for(auto it=res.begin()+1;it!=res.end();it++)
        printf("%d ",*it);
    return 0;
}