#include<bits/stdc++.h>
using namespace std;
const int N=40010;
int n,vis[N],phi[N],prime[N],p=0,ans=0;
int main(){
    scanf("%d",&n);
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
    for(int i=1;i<n;i++)
        ans+=phi[i];
    if(n==1)    printf("0");
    else        printf("%d",2*ans+1);
    return 0;
}