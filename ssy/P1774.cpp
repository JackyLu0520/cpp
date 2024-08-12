#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n;
pair<int,int> a[N];
int b[N],c[N];
inline int lowbit(int x){return x&-x;}
void add(int x,int k){
    while(x<=n){
        c[x]+=k;
        x+=lowbit(x);
    }
}
int getsum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%lld",&t);
        a[i]=make_pair(t,i);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)   b[a[i].second]=i;
    int ans=0;
    for(int i=n;i>=1;i--){
        int x=b[i];
        ans+=getsum(x-1);
        add(x,1);
    }
    printf("%lld",ans);
    return 0;
}