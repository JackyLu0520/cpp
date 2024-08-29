#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const int N=15;
struct matrix{
    double a[N][N];int r,c;
    matrix(){}
    matrix(int _r,int _c){
        r=_r;c=_c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                a[i][j]=0;
    }
    double *const operator[](const int i){return a[i];}
    void rswap(int i,int j){
        for(int k=1;k<=c;k++)
            swap(a[i][k],a[j][k]);
    }
    void rmul(int i,double k){
        for(int j=1;j<=c;j++)
            a[i][j]*=k;
    }
    void radd(int i,int j,double k){
        for(int l=1;l<=c;l++)
            a[i][l]+=k*a[j][l];
    }
}m;
void Gauss(){
    for(int i=1;i<=m.r;i++){
        int t=i;
        for(int j=i+1;j<=m.r;j++)
            if(fabs(m[j][i])>fabs(m[t][i]))
                t=j;
        m.rswap(i,t);
        m.rmul(i,1/m[i][i]);
        for(int j=1;j<=m.r;j++)
            if(i!=j)
                m.radd(j,i,-m[j][i]);
    }
}
int n;
double a[N][N];
int main(){
    scanf("%d",&n);
    m=matrix(n,n+1);
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            m[i][j]=2*(a[i+1][j]-a[i][j]);
        for(int j=1;j<=n;j++)
            m[i][n+1]+=a[i+1][j]*a[i+1][j]-a[i][j]*a[i][j];
    }
    Gauss();
    for(int i=1;i<=n;i++)
        printf("%.3lf ",m[i][n+1]);
    return 0;
}