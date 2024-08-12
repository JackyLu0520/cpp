#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
int n,k;
pair<int,int> a[N];
int t[N],cnt;
int tmp[N];
void msort(int l,int r){
    if(l==r)    return;
    int mid=(l+r)/2;
    msort(l,mid);msort(mid+1,r);
    int i,j,tp;
    for(i=l,j=mid+1,tp=l;i<=mid&&j<=r;)
        if(t[i]>t[j])
            tmp[tp++]=t[j++];
        else{
            tmp[tp++]=t[i++];
            cnt+=r-j+1;
        }
    for(;i<=mid;i++)    tmp[tp++]=t[i];
    for(;j<=r;j++)    tmp[tp++]=t[j];
    for(i=l;i<=r;i++)    t[i]=tmp[i];
}
bool check(int m){
    for(int i=1;i<=n;i++)
        t[i]=a[i].second-m*a[i].first;
    cnt=0;
    msort(1,n);
    return cnt>=k;
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].first,&a[i].second);
    sort(a+1,a+n+1,[](pair<int,int> a,pair<int,int> b){return a.first==b.first?a.second>b.second:a.first<b.first;});
    int l=-INF,r=INF;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))  l=mid;
        else            r=mid-1;
    }
    printf("%lld",l);
    return 0;
}