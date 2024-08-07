#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e6+10;
long long n,m,r[N],d[M],s[M],t[M],diff[N],tmp[N];
bool check(int x){
    memset(diff,0,sizeof(diff));
    memset(tmp,0,sizeof(diff));
    for(int i=1;i<=x;i++){
        diff[s[i]]+=d[i];
        diff[t[i]+1]-=d[i];
    }
    for(int i=1;i<=n;i++)   tmp[i]=tmp[i-1]+diff[i];
    for(int i=1;i<=n;i++)
        if(tmp[i]>r[i])
            return 0;
    return 1;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&r[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&d[i],&s[i],&t[i]);
    if(check(m)){
        printf("0");return 0;
    }
    long long l=1,r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))
            l=mid+1;
        else
            r=mid;
    }
    printf("-1\n%lld",l);
    return 0;
}