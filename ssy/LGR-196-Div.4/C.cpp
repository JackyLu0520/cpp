#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],b[N],ans=0;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)
        ans+=a[i]+b[i];
    printf("%lld",(ans+1)/2);
    return 0;
}