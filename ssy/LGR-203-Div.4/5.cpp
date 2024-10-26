#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e4+10;
int n,m,r,k;
int prime[N],p=0;
bool notprime[N];
int main(){
    scanf("%d%d%d%d",&n,&m,&r,&k);
    notprime[1]=1;
    for(int i=2;i<=n;i++){
        if(!notprime[i])  prime[++p]=i;
        for(int j=1;j<=p&&i*prime[j]<=n;j++){
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)   break;
        }
    }
    for(int i=n;i>=1;i--)
        if(!notprime[i]&&i%m==r){
            k--;
            if(k==0){
                printf("%d",i);
                return 0;
            }
        }
    printf("-1");
    return 0;
}