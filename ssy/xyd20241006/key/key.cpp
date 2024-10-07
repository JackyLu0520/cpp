#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e3+10;
int n;
long long a[N],sum=0;
char s1[N],s2[N];
vector<long long>res;
long long solveres;
long long solve(vector<long long> x){
    long long ret=0;
    sort(x.begin(),x.end(),greater<long long>());
    for(long long i=0;i<x.size();i++)
        ret+=(i+1)*x[i];
    return ret+sum*x.size();
}
bool b[N];
vector<int>p;
vector<long long>t;
long long ans=0x7fffffffffffffff;
void dfs(int now){
    if(now==p.size()){
        ans=min(ans,solve(t));
        return;
    }
    t.push_back(a[p[now]]);
    t.push_back(-a[p[now]]);
    dfs(now+1);
    t.pop_back();t.pop_back();
    dfs(now+1);
}
int main(){
    freopen("key.in","r",stdin);
    freopen("key.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    scanf("%s%s",s1+1,s2+1);
    for(int i=1;i<=n;i++)
        if(s1[i]=='1')  sum+=a[i];
    for(int i=1;i<=n;i++)
        if(s1[i]>s2[i]) res.push_back(-a[i]);
        else if(s1[i]<s2[i])    res.push_back(a[i]);
    solveres=solve(res);
    for(int i=1;i<=n;i++)
        if(s1[i]=='1'&&s2[i]=='1')
            p.push_back(i);
    t=res;
    dfs(0);
    printf("%lld",ans);
    return 0;
}