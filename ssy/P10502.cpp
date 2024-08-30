#include<bits/stdc++.h>
using namespace std;
const int N=35;
int n,k,m;
struct matrix{//1~r,1~c
    int a[2*N][2*N]={0},r,c;
    matrix(){}
    matrix(int _r,int _c){r=_r;c=_c;}
    int *const operator[](const int i){return a[i];}
    void set(int _r,int _c,matrix x){//set x on (_r+1,_c+1)
        for(int i=1;i<=x.r;i++)
            for(int j=1;j<=x.c;j++)
                a[_r+i][_c+j]=x[i][j]%m;
    }
    matrix friend operator*(matrix a,matrix b){
        if(a.c!=b.r)    return matrix(1,1);
        matrix ans(a.r,b.c);
        for(int i=1;i<=a.r;i++)
            for(int j=1;j<=b.c;j++)
                for(int k=1;k<=a.c;k++)
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%m)%m;
        return ans;
    }
};
matrix E(int x){matrix t(x,x);for(int i=1;i<=x;i++)t[i][i]=1;return t;}
matrix A,M;
matrix binpow(matrix a,int b){
    if(a.r!=a.c)    return matrix(1,1);
    matrix ans=E(a.r);
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;b>>=1;
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    A=matrix(n,n);M=matrix(2*n,2*n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&A[i][j]);
    M.set(0,0,A);M.set(n,0,A);M.set(n,n,E(n));
    M=binpow(M,k);
    for(int i=n+1;i<=2*n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
    return 0;
}