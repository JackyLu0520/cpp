#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,X=1e3+10;
int n,x;
int lose[N],win[N],use[N];
long long f[N][X];
int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&lose[i],&win[i],&use[i]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=x;j++)
            if(j-use[i]>=0)
                f[i][j]=max(f[i-1][j]+lose[i],f[i-1][j-use[i]]+win[i]);
            else
                f[i][j]=f[i-1][j]+lose[i];
    printf("%lld",5*f[n][x]);
    return 0;
}