#include<bits/stdc++.h>
using namespace std;
constexpr double eps=1e-4;
constexpr int N=1e3+10;
int n,k;
int a[N],b[N];
bool check(double x){
    double c[N];
    for(int i=1;i<=n;i++)
        c[i]=a[i]-x*b[i];
    sort(c+1,c+n+1);
    double sum=0;
    for(int i=k+1;i<=n;i++)
        sum+=c[i];
    return sum>=0;
}
int main(){
    while(1){
        scanf("%d%d",&n,&k);
        if(n==0&&k==0)  break;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        double l=0,r=1;
        while(fabs(r-l)>=eps){
            double mid=(l+r)/2;
            if(check(mid))  l=mid;
            else            r=mid;
        }
        printf("%d\n",int(100*l+0.5));
    }
    return 0;
}