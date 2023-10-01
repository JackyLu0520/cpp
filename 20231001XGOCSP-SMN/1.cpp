#include<bits/stdc++.h>
using namespace std;
const int MOD=99991;
long long a,b;
long long c[15]={0},m=0,ans=1;
int main(){
    scanf("%lld%lld",&a,&b);
    for(int i=2;i*i<=a;i++)
        if(a%i==0){
            m++;
            while(a%i==0)   a/=i,c[m]++;
            c[m]=(c[m]*(b%MOD))%MOD;
        }
    if(a!=0)    c[++m]=b%MOD;
    for(int i=1;i<=m;i++)
        ans=(ans*(c[i]+1))%MOD;
    printf("%lld",ans);
    return 0;
}