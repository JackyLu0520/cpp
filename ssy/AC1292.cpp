#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
bool notprime[N];
int prime[N],t=0;
int main(){
    for(int i=2;i<N;i++)
        if(!notprime[i]){
            prime[++t]=i;
            for(int j=i+i;j<N;j+=i)
                notprime[j]=1;
        }
    while(1){
        bool f=0;
        scanf("%d",&n);
        if(n==0)    break;
        for(int i=1;i<=t;i++)
            if(!notprime[n-prime[i]]){
                printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
                f=1;break;
            }
        if(!f)  printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}