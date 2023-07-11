#include<cstdio>
using namespace std;
const int MAXN=2e5;
int n,a[MAXN+10];
long long s[MAXN+10];
long long ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    /*for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans+=a[i]*a[j];*/
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
        ans+=s[i-1]*a[i];
    printf("%lld",ans);
    return 0;
}