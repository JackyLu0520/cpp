#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
struct e{ll h,p;e(){}e(ll _h,ll _p){h=_h,p=_p;}}a[N];
priority_queue<ll>q;
int now=0;
int main(){
    freopen("invader.in","r",stdin);
    freopen("invader.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll h,p;scanf("%lld%lld",&h,&p);
        a[i]=e(h,p);
    }
    sort(a+1,a+n+1,[](e a,e b){return a.h+a.p<b.h+b.p;});
    for(int i=1;i<=n;i++){
        if(now<=a[i].p){
            now+=a[i].p;
            q.push(a[i].p);
        }else if(now-q.top()<=a[i].p&&a[i].p<=q.top()){
            now-=q.top();q.pop();
            now+=a[i].p;q.push(a[i].p);
        }
    }
    printf("%lld",q.size());
    return 0;
}