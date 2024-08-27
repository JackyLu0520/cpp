#include<bits/stdc++.h>
using namespace std;
int p,q,a1,a2,n,m;
struct matrix{
    long long a[2][2]={0};int x,y;
    matrix(){}
    matrix(int _x,int _y){x=_x,y=_y;}
    long long * const operator[](const int x){
        return a[x];
    }
    matrix friend operator*(matrix a,matrix b){
        if(a.y!=b.x)    return matrix(1,1);
        matrix ans(a.x,b.y);
        for(int i=0;i<a.x;i++)
            for(int j=0;j<b.y;j++)
                for(int k=0;k<a.y;k++)
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%m)%m;
        return ans;
    }
}a(1,2),A(2,2);
matrix id(int x){matrix tmp(x,x);for(int i=0;i<x;i++)  tmp[i][i]=1;return tmp;}
matrix binpow(matrix a,int b){
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
    scanf("%d%d%d%d%d%d",&p,&q,&a1,&a2,&n,&m);
    a[0][0]=a2;a[0][1]=a1;
    A[0][0]=p;A[1][0]=q;A[0][1]=1;
    if(n==1)    printf("%d",a1);
    else        printf("%lld",(a*binpow(A,n-2))[0][0]);
    return 0;
}