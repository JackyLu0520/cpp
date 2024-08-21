#include<bits/stdc++.h>
using namespace std;
int main(){
    double x[2],y[2];scanf("%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1]);
    int i=0,j=1;
    double a=(x[j]*y[i]-x[i]*y[j])/(x[i]*x[i]*x[j]-x[j]*x[j]*x[i]);
    double b=(x[j]*x[j]*y[i]-x[i]*x[i]*y[j])/(x[i]*x[j]*x[j]-x[j]*x[i]*x[i]);
    printf("%lf %lf",a,b);
    return 0;
}