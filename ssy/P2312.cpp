#include<bits/stdc++.h>
using namespace std;
const int MOD1=1e9+7,MOD2=998244353;
const int N=110,M=1e6+10;
int n,m;
pair<long long,long long> read(){
    long long sgn=1,x1=0,x2=0;char c;
    do{
        c=getchar();
        if(c=='-')
            sgn=-1;
    }while(isdigit(c));
    do{
        x1=(x1*10+c-'0')%MOD1;
        x2=(x2*10+c-'0')%MOD2;
        c=getchar();
    }while(!isdigit(c));
    return make_pair(sgn*x1,sgn*x2);
}
int a1[N],a2[N];
long long f(int x,int a[],const int mod){
    long long ans=a[n];
    for(int i=n-1;i>=0;i--)
        ans=(ans*x+a[i])%mod;
    return ans;
}
int cnt=0,res[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        tie(a1[i],a2[i])=read();
    for(int i=1;i<=m;i++)
        if(!f(i,a1,MOD1)&&!f(i,a2,MOD2))
            res[++cnt]=i;
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
        printf("%d\n",res[i]);
    return 0;
}