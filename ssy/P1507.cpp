#include<bits/stdc++.h>
using namespace std;
const int N=60,H=410,T=410;
int n,hmax,tmax,h[N],t[N],k[N];
int f[N][H][T];
int main(){
    scanf("%d%d%d",&hmax,&tmax,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&h[i],&t[i],&k[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=hmax;j++)
            for(int l=1;l<=tmax;l++)
                if(j>=h[i]&&l>=t[i])
                    f[i][j][l]=max(f[i-1][j][l],f[i-1][j-h[i]][l-t[i]]+k[i]);
                else
                    f[i][j][l]=f[i-1][j][l];
    printf("%d",f[n][hmax][tmax]);
    return 0;
}