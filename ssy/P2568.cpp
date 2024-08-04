#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long n,vis[N],phi[N],prime[N],p=0,sum[N]={0},ans=0;
int main(){
    scanf("%lld",&n);
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            vis[i]=i;
            prime[++p]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=p;j++){
            if(i*prime[j]>n)    break;
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+phi[i];
    for(int i=1;i<=p;i++)
        ans+=2*sum[n/prime[i]]-1;
    printf("%lld",ans);
    return 0;
}