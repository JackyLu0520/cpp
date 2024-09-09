#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,f[N];
bool notprime[N];
int prime[N],p=0;
int ans=N;
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(!notprime[i]){
            f[i]=i;
            prime[++p]=i;
        }
        for(int j=1;j<=p&&i*prime[j]<=n;j++){
            notprime[i*prime[j]]=1;
            f[i*prime[j]]=max(f[i],prime[j]);
            if(i%prime[j]==0)   break;
        }
    }
    if(!notprime[n]||n==1){printf("-1");return 0;}
    for(int i=n-f[n]+1;i<=n;i++)
        if(notprime[i])
            ans=min(ans,i-f[i]+1);
    printf("%d",ans);
    return 0;
}