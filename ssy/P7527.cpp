#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,A=2e5+10;
int n,a[N];
int lowbit(int x){return x&-x;}
int t[N];
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=k;
}
int getsum(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
        ans+=t[i];
    return ans;
}
int p[A],ans=0;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        p[a[i]]=n+1;
    }
    for(int i=n;i>=1;i--){
        ans+=getsum(p[a[i]]-1);
        add(p[a[i]],-1);
        add(i,1);
        p[a[i]]=i;
    }
    printf("%lld",ans);
    return 0;
}