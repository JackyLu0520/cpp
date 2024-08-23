#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-6;
long long sgn(long double x){
    if(x>-eps&&x<eps)   return 0;
    return x>eps?1:-1;
}
int main(){
    long double a;
    scanf("%Lf",&a);
    printf("%lld",sgn(a)*(long long)(fabs(a)));
    return 0;
}