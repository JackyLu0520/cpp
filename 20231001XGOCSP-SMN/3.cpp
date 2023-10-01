#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5;
int n,s[MAXN+10];
long long a[MAXN+10]={0},b[MAXN+10]={0},ans=0;//a:小于;b:大于
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            if(s[i]>s[j])   a[i]++;
            else if(s[i]<s[j])  b[i]++;
    for(int i=1;i<=n-2;i++)
        for(int j=i+1;j<=n-1;j++)
            if(s[i]>s[j])   ans+=a[j];
            else if(s[i]<s[j])  ans+=b[j];
    printf("%lld",ans);
    return 0;
}