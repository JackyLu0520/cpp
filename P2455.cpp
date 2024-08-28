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
void Gauss(matrix &m){
    for(int i=0,j=0;i<m.x&&j<m.x;j++){
        int t=i;
        for(int k=i+1;k<m.x;k++)
            if(fabs(m[k][j])>fabs(m[t][j])) t=k;
        m.rswap(i,t);
        if(fabs(m[i][j])<eps)   continue;
        m.rmul(i,1/m[i][j]);
        for(int k=0;k<m.x;k++)
            if(i!=k)    m.radd(k,i,-m[k][j]);
        i++;
    }
}
int check(matrix m){
    if(fabs(m[m.x-1][m.x-1])>eps)   return 1;
    for(int i=m.x-1;i>=0;i--){
        bool f=1;
        for(int j=0;j<m.x;j++)
            if(fabs(m[i][j])>eps){
                f=0;break;
            }
        if(f&&fabs(m[i][m.x])>eps)
            return -1;
    }
    return 0;
}
int main(){
    int n;scanf("%d",&n);
    m.x=n;m.y=n+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            scanf("%lf",&m[i][j]);
    Gauss(m);
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++)
            printf("%.2lf ",m[i][j]);
        printf("\n");
    }*/
    int c=check(m);
    if(c==-1)   printf("-1");
    else if(c==0)   printf("0");
    else{
        for(int i=0;i<n;i++)
            printf("x%d=%.2lf\n",i+1,m[i][n]);
    }
    return 0;
}