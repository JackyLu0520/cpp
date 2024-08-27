#include<bits/stdc++.h>
using namespace std;
const long long M=105,MOD=1e9+7;
long long n,m1,a1[M],m2,a2[M],m=0,a[M],p=1,q=1;
struct matrix{
    long long a[M][M]={0},x,y;
    matrix(){}
    matrix(int _x,int _y){
        x=_x;y=_y;
    }
    long long * const operator[](const int i){
        return a[i];
    }
    matrix friend operator*(matrix a,matrix b){
        if(a.y!=b.x)    return matrix(1,1);
        matrix ans(a.x,b.y);
        for(int i=0;i<a.x;i++)
            for(int j=0;j<b.y;j++)
                for(int k=0;k<a.y;k++)
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
        return ans;
    }
};
matrix id(int x){matrix t(x,x);for(int i=0;i<x;i++)t[i][i]=1;return t;}
matrix binpow(matrix a,long long b){
    if(a.x!=a.y)    return matrix(1,1);
    matrix ans=id(a.x);
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld",&n);
    scanf("%lld",&m1);
    for(int i=1;i<=m1;i++)
        scanf("%lld",&a1[i]);
    scanf("%lld",&m2);
    for(int i=1;i<=m2;i++)
        scanf("%lld",&a2[i]);
    sort(a1+1,a1+m1+1,sizeof(a1));
    sort(a2+1,a2+m2+1,sizeof(a2));
    while(p<=m1&&q<=m2)
        if(a1[p]==a2[q]){
            a[++m]=a1[p];p++;q++;
        }else if(a1[p]>a2[q])
            q++;
        else
            p++;
    int size=a[m];
    matrix dp1(1,size),dp2(size,size);
    dp1[size-1]=0;
    for(int i=1;i<size;i++)
}