#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const int N=105;
struct matrix{
    double a[N][N];int x,y;
    matrix(){}
    matrix(int _x,int _y){
        x=_x,y=_y;
        for(int i=0;i<x;i++)
            for(int j=0;i<y;j++)
                a[i][j]=0;
    }
    double * const operator[](const int i){return a[i];}
    void rswap(int i,int j){//r[i]<=>r[j]
        for(int k=0;k<y;k++)
            swap(a[i][k],a[j][k]);
    }
    void rmul(int i,double k){//r[i]*k
        for(int j=0;j<y;j++)
            a[i][j]*=k;
    }
    void radd(int i,int j,double k){//r[i]+k*r[j]
        for(int t=0;t<y;t++)
            a[i][t]+=a[j][t]*k;
    }
}m;
bool Gauss(matrix &m){
    for(int i=0;i<m.x;i++){
        int t=i;
        for(int j=i+1;j<m.x;j++)
            if(fabs(m[j][i])>fabs(m[t][i])) t=j;
        m.rswap(i,t);
        if(fabs(m[i][i])<eps)   return 0;
        m.rmul(i,1/m[i][i]);
        for(int j=0;j<m.x;j++)
            if(i!=j)    m.radd(j,i,-m[j][i]);
    }
    return 1;
}
int main(){
    int n;scanf("%d",&n);
    m.x=n;m.y=n+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            scanf("%lf",&m[i][j]);
    if(Gauss(m)){
        for(int i=0;i<n;i++)
            printf("%.2lf\n",m[i][n]);
    }else
        printf("No Solution");
    return 0;
}