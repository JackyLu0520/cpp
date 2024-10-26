#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int n,q;
bool notprime[N];
int prime[N],p=0;
int main(){
    scanf("%d%d",&n,&q);
    notprime[1]=1;
    for(int i=2;i<=n;i++){
        if(!notprime[i])
            prime[++p]=i;
        for(int j=1;i*prime[j]<=n&&j<=p;j++){
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)   break;
        }
    }
    while(q--){
        int k;scanf("%d",&k);
        printf("%d\n",prime[k]);
    }
    return 0;
}