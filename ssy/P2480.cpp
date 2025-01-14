#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=999911658,P[4]={2,3,4679,35617};
inline int binpow(int a,int b,const int p){
    int ans=1;
    a%=p;
    while(b){
        if(b&1) ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}
inline int inv(int a,const int p){
    return binpow(a,p-2,p);
}
inline int C(int n,int m,const int p){
    if(n<m) return 0;
    int up=1,down=1;
    for(int i=1;i<=m;i++){
        up=up*(n-i+1)%p;
        down=down*i%p;
    }
    return up*inv(down,p)%p;
}
int lucas(int n,int m,const int p){
    if(n<p&&m<p)    return C(n,m,p);
    return C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
int n,g,a[4];
inline int CRT(){
    int ans=0;
    for(int i=0;i<4;i++){
        int m=M/P[i];
        ans=(ans+a[i]*m%M*inv(m,P[i])%M)%M;
    }
    return ans;
}
signed main(){
    scanf("%lld%lld",&n,&g);
    if(g%(M+1)==0){
        printf("0\n");
        return 0;
    }
    int i;
    for(int j=0;j<4;j++){
        for(i=1;i*i<n;i++)
            if(n%i==0){
                a[j]=(a[j]+lucas(n,i,P[j]))%P[j];
                a[j]=(a[j]+lucas(n,n/i,P[j]))%P[j];
            }
        if(i*i==n)
            a[j]=(a[j]+lucas(n,i,P[j]))%P[j];
    }
    printf("%lld\n",binpow(g,CRT(),M+1));
    return 0;
}