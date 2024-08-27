#include<bits/stdc++.h>
using namespace std;
const int N=35,MOD=2017;
int n,m;
struct matrix{
    long long a[N][N]={0};int x,y;
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
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
        return ans;
    }
}M;
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
    scanf("%d%d",&n,&m);
    M=id(n+1);
    for(int i=1;i<=n;i++)   M[i][0]=1;
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        M[x][y]=1;M[y][x]=1;
    }
    int t;scanf("%d",&t);
    matrix matans=binpow(M,t);
    int ans=0;
    for(int i=0;i<=n;i++)
        ans=(ans+matans[1][i])%MOD;
    printf("%d",ans);
    return 0;
}