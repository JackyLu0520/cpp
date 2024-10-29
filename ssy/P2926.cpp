#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+10,A=1e6+10;
int n,a[N],c[A];
long long ans[A];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
    for(int i=1;i<A;i++)
        for(int j=i;j<A;j+=i)
            ans[j]+=c[i];
    for(int i=1;i<=n;i++)
        printf("%lld\n",ans[a[i]]-1);
    return 0;
}