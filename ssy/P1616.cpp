#include<bits/stdc++.h>
using namespace std;
const int T=1e7+10,M=1e4+10;
int t,m,w[M],c[M];
long long f[T];
int main(){
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=t;j++)
            if(j-w[i]>=0)
                f[j]=max(f[j],f[j-w[i]]+c[i]);
    printf("%lld",f[t]);
    return 0;
}