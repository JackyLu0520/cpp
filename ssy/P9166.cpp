#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,x,cnt=0;
int diff[N],b[N];
bool v[N];
int ans[N],p=0;
int main(){
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        diff[l]++;diff[r+1]--;
        if(l<x) v[l]=1;
        if(r>x) v[r]=1;
    }
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+diff[i];
    for(int i=x+1;i<=n&&b[i]!=0;i++)
        if(v[i])    ans[++p]=i;
    for(int i=x-1;i>=1&&b[i]!=0;i--)
        if(v[i])    ans[++p]=i;
    sort(ans+1,ans+p+1);
    for(int i=1;i<=p;i++)
        printf("%d ",ans[i]);
    return 0;
}