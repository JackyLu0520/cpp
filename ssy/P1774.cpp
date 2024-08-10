#include<bits/stdc++.h>
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
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        a[i]=make_pair(t,i);
    }
    sort(a+1,a+n+1,[](pair<int,int> a,pair<int,int> b){return a.first==b.first?a.second>b.second:a.first>b.first;});
    for(int i=1;i<=n;i++)   b[a[i].second]=i;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=b[i];
        ans+=getsum(x-1);
        add(x,1);
    }
    printf("%d",ans);
    return 0;
}