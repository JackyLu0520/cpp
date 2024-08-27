#include<bits/stdc++.h>
using namespace std;
const int N=110,MOD=1e9+7;
long long n,k;
struct matrix{
    long long a[N][N]={0};
    long long * const operator[](const int x){
        return a[x];
    }
    matrix friend operator*(matrix a,matrix b){
        matrix c;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
        return c;
    }
}m;
matrix binpow(matrix a,long long b){
    matrix ans;
    for(int i=1;i<=n;i++)   ans[i][i]=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
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