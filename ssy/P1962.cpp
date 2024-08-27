#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
struct matrix{
    long long a[2][2]={0};
    long long * const operator[](const int x){
        return a[x];
    }
    matrix friend operator*(matrix a,matrix b){
        matrix c;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
        return c;
    }
}m;
matrix binpow(matrix a,long long b){
    matrix ans;
    ans[0][0]=ans[1][1]=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    m[0][0]=m[0][1]=m[1][0]=1;
    long long n;
    scanf("%lld",&n);
    printf("%lld\n",binpow(m,n)[0][1]);
    return 0;
}