#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c,n,vis[N],phi[N],prime[N],p=0,s[N];
int main(){
    phi[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            vis[i]=i;
            prime[++p]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=p;j++){
            if(i*prime[j]>N)    break;
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
    for(int i=1;i<N;i++)
        s[i]=s[i-1]+phi[i];
    scanf("%d",&c);
    for(int i=1;i<=c;i++){
        scanf("%d",&n);
        printf("%d %d %d\n",i,n,2*s[n]+1);
    }
    return 0;
}