#include<bits/stdc++.h>
using namespace std;
long long m,a,c,x0,n,g;
long long binmul(long long a,long long b){
    long long ans=0;
    while(b){
        if(b&1) ans=(ans+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return ans;
}
struct matrix{
    long long a[2][2]={0};int x,y;
    matrix(){}
    matrix(int _x,int _y){x=_x,y=_y;}
    long long * const operator[](const int i){
        return a[i];
    }
    matrix friend operator*(matrix a,matrix b){
        if(a.y!=b.x)    return matrix(1,1);
        matrix ans(a.x,b.y);
        for(int i=0;i<a.x;i++)
            for(int j=0;j<b.y;j++)
                for(int k=0;k<a.y;k++)
                    ans[i][j]=(ans[i][j]+binmul(a[i][k],b[k][j])%m)%m;
        return ans;
    }
}o(1,2),A(2,2);
matrix id(int x){matrix tmp(x,x);for(int i=0;i<x;i++)  tmp[i][i]=1;return tmp;}
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
    scanf("%lld%lld%lld%lld%lld%lld",&m,&a,&c,&x0,&n,&g);
    o[0][0]=x0;o[0][1]=1;
    A[0][0]=a;A[1][0]=c;A[1][1]=1;
    printf("%lld",(o*binpow(A,n))[0][0]%g);
    return 0;
}