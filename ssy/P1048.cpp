#include<bits/stdc++.h>
using namespace std;
const int T=1010,M=110;
int t,m,w[M],c[M];
int f[T];
int main(){
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=m;i++)
        for(int j=t;j>=1;j--)
            if(j-w[i]>=0)
                f[j]=max(f[j],f[j-w[i]]+c[i]);
    printf("%d",f[t]);
    return 0;
}