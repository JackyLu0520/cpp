#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int a[N],b[N];
double x;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        if(a[i]==1||b[i]==1){
            printf("-1\n");
            return 0;
        }
    x=m*1.0/(b[1]-1)*b[1];
    for(int i=n;i>=2;i--){
        x*=1.0*a[i]/(a[i]-1);
        x*=1.0*b[i]/(b[i]-1);
    }
    x*=1.0*a[1]/(a[1]-1);
    printf("%.10f\n",x-m);
    return 0;
}