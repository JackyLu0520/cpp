#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e6+10,A=1e6+10;
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
int m,p[A];
struct query{
    int l,r,id;
    bool operator < (const query& a) const{
        return r<a.r;
    }
}q[M];
int ans[M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    for(int i=1,ptr=1;i<=n;i++){
        if(p[a[i]]) add(p[a[i]],-1);
        add(i,1);
        p[a[i]]=i;
        for(;q[ptr].r==i;ptr++) ans[q[ptr].id]=getsum(q[ptr].r)-getsum(q[ptr].l-1);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}