#include<bits/stdc++.h>
using namespace std;
constexpr int N=110,MOD=1e9+7;
long long n,k;
struct matrix{
    long long a[N][N]={0};
    long long *const operator[](const int i){return a[i];}
    matrix friend operator*(matrix x,matrix y){
        matrix z;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=1;k<=n;k++)
                    z[i][j]=(z[i][j]+x[i][k]*y[k][j]%MOD)%MOD;
        return z;
    }
}m;
matrix id(){matrix x;for(int i=1;i<=n;i++)x[i][i]=1;return x;}
matrix binpow(matrix x,long long y){
    matrix ans=id();
    while(y){
        if(y&1) ans=ans*x;
        x=x*x;
        y>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&m[i][j]);
    m=binpow(m,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%lld ",m[i][j]);
        printf("\n");
    }
    return 0;
}